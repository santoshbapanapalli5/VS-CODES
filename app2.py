import streamlit as st
import pandas as pd
import datetime
import math
import matplotlib.pyplot as plt

# -------------------------------------------------------------
# SETUP & STYLING
# -------------------------------------------------------------
st.set_page_config(
    page_title="Intelligent Academic Planner",
    page_icon="🎓",
    layout="wide",
    initial_sidebar_state="expanded"
)

# Custom CSS for Professional UI Styling
st.markdown("""
    <style>
    /* Main container background gradient */
    .stApp {
        background: linear-gradient(to bottom right, #f8f9fa, #e9ecef);
    }
    
    /* Custom Header Banner */
    .header-banner {
        background: linear-gradient(135deg, #1e3c72 0%, #2a5298 100%);
        padding: 24px;
        border-radius: 12px;
        color: white;
        margin-bottom: 25px;
        box-shadow: 0 4px 6px rgba(0,0,0,0.1);
    }
    .header-banner h1 {
        color: white !important;
        margin: 0;
        font-weight: 700;
    }
    .header-banner p {
        color: #e0e6ed;
        margin-top: 8px;
        margin-bottom: 0;
        font-size: 1.05rem;
    }

    /* Card Containers */
    .metric-card {
        background-color: white;
        padding: 18px;
        border-radius: 10px;
        border-left: 5px solid #2a5298;
        box-shadow: 0 2px 4px rgba(0,0,0,0.05);
        margin-bottom: 15px;
    }
    
    /* Button Styling */
    div.stButton > button {
        background: linear-gradient(135deg, #1e3c72 0%, #2a5298 100%);
        color: white;
        border: none;
        padding: 12px 24px;
        border-radius: 8px;
        font-weight: 600;
        font-size: 1rem;
        transition: all 0.3s ease;
        width: 100%;
    }
    div.stButton > button:hover {
        background: linear-gradient(135deg, #2a5298 0%, #1e3c72 100%);
        box-shadow: 0 4px 12px rgba(42, 82, 152, 0.3);
        color: white;
    }
    </style>
""", unsafe_allow_html=True)

# -------------------------------------------------------------
# HEADER BANNER
# -------------------------------------------------------------
st.markdown("""
    <div class="header-banner">
        <h1>🎓 Intelligent Academic Planner</h1>
        <p>An AI-driven, practical scheduling engine that breaks tasks into realistic chunks and interleaves work across multiple days.</p>
    </div>
""", unsafe_allow_html=True)

# -------------------------------------------------------------
# SIDEBAR: CONFIGURATION & INPUTS
# -------------------------------------------------------------
st.sidebar.header("🗓️ Student Allocation")
daily_hours = st.sidebar.slider("Daily Study Bandwidth (Hours/Day):", min_value=1, max_value=12, value=4)
days_to_plan = st.sidebar.slider("Planning Horizon (Days):", min_value=3, max_value=14, value=7)
max_chunk_hours = st.sidebar.slider("Max Session Duration (Hours):", min_value=1, max_value=4, value=2)

total_available_hours = daily_hours * days_to_plan
st.sidebar.markdown("---")
st.sidebar.metric("Total Capacity Budget", f"{total_available_hours} Hours")

# -------------------------------------------------------------
# SESSION STATE MANAGEMENT
# -------------------------------------------------------------
today = datetime.date.today()

if "tasks_df" not in st.session_state:
    default_tasks = [
        {"Task Name": "Data Structures Assignment", "Due Date": today + datetime.timedelta(days=2), "Effort Required (Hours)": 4, "Priority": "High"},
        {"Task Name": "Math Quiz Preparation", "Due Date": today + datetime.timedelta(days=1), "Effort Required (Hours)": 3, "Priority": "Critical"},
        {"Task Name": "SIH Prototype Implementation", "Due Date": today + datetime.timedelta(days=5), "Effort Required (Hours)": 12, "Priority": "Critical"},
        {"Task Name": "Digital Electronics Lab Record", "Due Date": today + datetime.timedelta(days=3), "Effort Required (Hours)": 5, "Priority": "Medium"},
        {"Task Name": "Humanities Essay Submission", "Due Date": today + datetime.timedelta(days=6), "Effort Required (Hours)": 2, "Priority": "Low"},
    ]
    st.session_state.tasks_df = pd.DataFrame(default_tasks)

st.subheader("📥 Task Input Interface")
st.caption("Set task target completion dates, estimated effort, and priority levels:")

df_input = st.data_editor(
    st.session_state.tasks_df,
    num_rows="dynamic",
    use_container_width=True,
    key="tasks_editor",
    column_config={
        "Task Name": st.column_config.TextColumn("Task Name", required=True),
        "Due Date": st.column_config.DateColumn("Due Date", min_value=today, required=True),
        "Effort Required (Hours)": st.column_config.NumberColumn("Effort (Hrs)", min_value=1, max_value=50, step=1, required=True),
        "Priority": st.column_config.SelectboxColumn("Priority", options=["Low", "Medium", "High", "Critical"], required=True)
    }
)

st.session_state.tasks_df = df_input

# -------------------------------------------------------------
# ALGORITHMIC ENGINE
# -------------------------------------------------------------
priority_mapping = {"Critical": 4, "High": 3, "Medium": 2, "Low": 1}

if st.button("⚡ Generate Practical Day-Wise Schedule"):
    cleaned_tasks = df_input.dropna(subset=["Task Name", "Due Date", "Effort Required (Hours)", "Priority"]).copy()
    
    if cleaned_tasks.empty:
        st.error("Please add at least one complete task to build a schedule!")
    else:
        cleaned_tasks["Due Date"] = pd.to_datetime(cleaned_tasks["Due Date"]).dt.date
        cleaned_tasks["Days to Deadline"] = cleaned_tasks["Due Date"].apply(lambda d: max(1, (d - today).days))
        cleaned_tasks["Effort Required (Hours)"] = pd.to_numeric(cleaned_tasks["Effort Required (Hours)"])
        cleaned_tasks["Priority_Weight"] = cleaned_tasks["Priority"].map(priority_mapping)

        cleaned_tasks["Urgency_Index"] = 1.0 / cleaned_tasks["Days to Deadline"]
        cleaned_tasks["Scheduling_Score"] = (cleaned_tasks["Priority_Weight"] * 1.5) + (cleaned_tasks["Urgency_Index"] * 2.0)

        tasks_sorted = cleaned_tasks.sort_values(by="Scheduling_Score", ascending=False).reset_index(drop=True)

        work_chunks = []
        for _, row in tasks_sorted.iterrows():
            total_hours = int(row["Effort Required (Hours)"])
            task_name = row["Task Name"]
            priority = row["Priority"]
            due_date = row["Due Date"]
            
            num_chunks = math.ceil(total_hours / max_chunk_hours)
            remaining = total_hours
            
            for c in range(num_chunks):
                chunk_size = min(remaining, max_chunk_hours)
                work_chunks.append({
                    "Task Name": task_name,
                    "Priority": priority,
                    "Due Date": due_date,
                    "Chunk Size": chunk_size,
                    "Scheduling_Score": row["Scheduling_Score"]
                })
                remaining -= chunk_size

        schedule_by_day = {today + datetime.timedelta(days=i): [] for i in range(days_to_plan)}
        day_capacity = {day: daily_hours for day in schedule_by_day}
        
        unscheduled_chunks = []

        for chunk in work_chunks:
            scheduled = False
            for day, free_hours in day_capacity.items():
                if day <= chunk["Due Date"] and free_hours >= chunk["Chunk Size"]:
                    start_time = daily_hours - free_hours
                    end_time = start_time + chunk["Chunk Size"]
                    
                    schedule_by_day[day].append({
                        "Task Name": chunk["Task Name"],
                        "Priority": chunk["Priority"],
                        "Session Duration": f"{chunk['Chunk Size']} hr(s)",
                        "Daily Slot": f"Hour {start_time:.1f} to Hour {end_time:.1f}",
                        "Due Date": chunk["Due Date"]
                    })
                    
                    day_capacity[day] -= chunk["Chunk Size"]
                    scheduled = True
                    break
            
            if not scheduled:
                unscheduled_chunks.append(chunk)

        # -------------------------------------------------------------
        # UI DISPLAY
        # -------------------------------------------------------------
        st.write("")
        st.success("🎯 Schedule Generated Successfully!")
        st.subheader("🗓️ Multi-Day Breakout Schedule")
        
        total_scheduled_hours = 0
        for day, sessions in schedule_by_day.items():
            day_str = day.strftime("%A, %b %d, %Y")
            used_hours = daily_hours - day_capacity[day]
            total_scheduled_hours += used_hours
            
            with st.expander(f"📅 {day_str} — Workload: {used_hours}/{daily_hours} Hours", expanded=True):
                if sessions:
                    df_day = pd.DataFrame(sessions)
                    
                    def highlight_urgency(val):
                        if val == "Critical":
                            return 'background-color: #ffe6e6; color: #990000; font-weight: bold;'
                        elif val == "High":
                            return 'background-color: #fff2e6; color: #cc6600;'
                        return ''
                    
                    st.dataframe(df_day.style.map(highlight_urgency, subset=["Priority"]), use_container_width=True)
                else:
                    st.info("🎈 Free day! No tasks allocated.")

        st.subheader("⚠️ Capacity Insights & Conflict Resolution")
        col1, col2 = st.columns(2)
        
        total_demand = cleaned_tasks["Effort Required (Hours)"].sum()
        
        with col1:
            st.markdown(f"""
                <div class="metric-card">
                    <h4>Capacity Overview</h4>
                    <p><b>Total Load Demand:</b> {total_demand} Hours</p>
                    <p><b>Scheduled Focus Hours:</b> {total_scheduled_hours} Hours</p>
                </div>
            """, unsafe_allow_html=True)
            
            if total_demand > total_available_hours:
                st.warning(f"🚨 **Workload Warning**: Demand exceeds available budget by {total_demand - total_available_hours} hours.")
            else:
                st.info("✅ Ideal Workload: All required tasks fit into your budget.")

        with col2:
            if unscheduled_chunks:
                st.error("❌ Deferred Task Sessions (Exceeded Capacity or Due Date Passed)")
                df_unscheduled = pd.DataFrame(unscheduled_chunks)[["Task Name", "Priority", "Chunk Size", "Due Date"]]
                st.dataframe(df_unscheduled, use_container_width=True)
            else:
                st.success("🎉 All task chunks successfully scheduled across your timeline.")

        st.subheader("📊 Daily Focus Distribution")
        
        # Styled Matplotlib Chart
        fig, ax = plt.subplots(figsize=(8, 2.8))
        fig.patch.set_facecolor('#f8f9fa')
        ax.set_facecolor('#ffffff')
        
        days_labels = [d.strftime("%b %d") for d in schedule_by_day.keys()]
        hours_allocated = [daily_hours - day_capacity[d] for d in schedule_by_day.keys()]
        
        bars = ax.bar(days_labels, hours_allocated, color="#2a5298", alpha=0.85, width=0.5, label="Allocated Hours")
        ax.axhline(daily_hours, color='#e74c3c', linestyle='--', linewidth=1.5, label="Daily Capacity Limit")
        
        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)
        ax.spines['left'].set_color('#cccccc')
        ax.spines['bottom'].set_color('#cccccc')
        
        ax.set_ylabel("Hours", fontsize=10, fontweight='bold', color='#333333')
        ax.legend(loc="upper right", frameon=True, facecolor='#ffffff', edgecolor='none')
        plt.tight_layout()
        st.pyplot(fig)  