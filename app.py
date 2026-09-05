import streamlit as st
import pandas as pd
import datetime
import matplotlib.pyplot as plt

# -------------------------------------------------------------
# SETUP & STYLING
# -------------------------------------------------------------
st.set_page_config(page_title="Intelligent Academic Planner", page_icon="🎓", layout="wide")

st.title("🎓 Intelligent Academic Planner — SIH Prototype")
st.markdown("An AI-driven, constraint-aware prioritization scheduling engine built for **IIITDM Jabalpur CSE — Internal SIH**.")

# -------------------------------------------------------------
# SIDEBAR: CONFIGURATION & INPUTS
# -------------------------------------------------------------
st.sidebar.header("🗓️ Available Student Allocation")
daily_hours = st.sidebar.slider("Your available hours per day:", min_value=1, max_value=12, value=4)
days_to_plan = st.sidebar.slider("Planning Horizon (Days):", min_value=3, max_value=14, value=7)

# Calculate total budget capacity
total_available_hours = daily_hours * days_to_plan
st.sidebar.metric("Total Free Budget Capacity", f"{total_available_hours} Hours")

# Default Sample Tasks for 5-10 MVP Task Criterion
default_tasks = [
    {"Task Name": "Data Structures Assignment", "Days to Deadline": 2, "Effort Required (Hours)": 4, "Priority": "High"},
    {"Task Name": "Math Quiz Preparation", "Days to Deadline": 1, "Effort Required (Hours)": 3, "Priority": "Critical"},
    {"Task Name": "SIH Prototype Implementation", "Days to Deadline": 5, "Effort Required (Hours)": 12, "Priority": "Critical"},
    {"Task Name": "Digital Electronics Lab Record", "Days to Deadline": 3, "Effort Required (Hours)": 5, "Priority": "Medium"},
    {"Task Name": "Humanities Essay Submission", "Days to Deadline": 6, "Effort Required (Hours)": 2, "Priority": "Low"},
]

st.header("📥 Task Input Interface")
st.write("Edit the initial set or append up to 10 distinct task parameters below:")

# Interactive Data Editor for the user to manipulate
df_input = st.data_editor(
    pd.DataFrame(default_tasks),
    num_rows="dynamic",
    column_config={
        "Task Name": st.column_config.TextColumn("Task Name", required=True),
        "Days to Deadline": st.column_config.NumberColumn("Days to Deadline", min_value=1, max_value=30, step=1, required=True),
        "Effort Required (Hours)": st.column_config.NumberColumn("Effort (Hrs)", min_value=1, max_value=50, step=1, required=True),
        "Priority": st.column_config.SelectboxColumn("Priority", options=["Low", "Medium", "High", "Critical"], required=True)
    }
)

# -------------------------------------------------------------
# BACKEND ALGORITHMIC ENGINE
# -------------------------------------------------------------
priority_mapping = {"Critical": 4, "High": 3, "Medium": 2, "Low": 1}

if st.button("⚡ Generate Optimal Schedule & Analytics"):
    if df_input.empty:
        st.error("Please add at least one task to build a schedule!")
    else:
        # Preprocessing & Normalization
        tasks = df_input.copy()
        tasks['Priority_Weight'] = tasks['Priority'].map(priority_mapping)
        
        # Priority Score Calculation: Combining Urgency (1/Deadline) and Task Weight
        # Prevents long-deadline heavy priority tasks from choking near-term critical deadlines
        tasks['Urgency_Index'] = 1.0 / tasks['Days to Deadline']
        tasks['Scheduling_Score'] = tasks['Priority_Weight'] * 1.5 + tasks['Urgency_Index'] * 2.0
        
        # Core Sort for the scheduling stream
        tasks_sorted = tasks.sort_values(by='Scheduling_Score', ascending=False).reset_index(drop=True)
        
        # Allocation & Conflict Resolution Engine
        scheduled_tasks = []
        dropped_tasks = []
        accumulated_hours = 0
        
        for idx, row in tasks_sorted.iterrows():
            if accumulated_hours + row['Effort Required (Hours)'] <= total_available_hours:
                accumulated_hours += row['Effort Required (Hours)']
                # Determine mock timeline mapping window
                start_window = accumulated_hours - row['Effort Required (Hours)']
                scheduled_tasks.append({
                    "Order": len(scheduled_tasks) + 1,
                    "Task Name": row['Task Name'],
                    "Priority": row['Priority'],
                    "Deadline Window (Days)": row['Days to Deadline'],
                    "Effort Required (Hours)": row['Effort Required (Hours)'],
                    "Schedule Timeline Allocation": f"Hour {start_window} to Hour {accumulated_hours}"
                })
            else:
                dropped_tasks.append({
                    "Task Name": row['Task Name'],
                    "Priority": row['Priority'],
                    "Effort Required (Hours)": row['Effort Required (Hours)'],
                    "Shortfall (Hours)": (accumulated_hours + row['Effort Required (Hours)']) - total_available_hours
                })
        
        # Output components UI
        st.success("🎯 Execution Strategy Generated Successfully!")
        
        # 1. Show Schedule Layout
        st.subheader("🗓️ Ordered Timeline Execution Schedule")
        if scheduled_tasks:
            df_schedule = pd.DataFrame(scheduled_tasks)
            
            # Highlighting urgent/high tasks styling logic
            def highlight_urgency(val):
                if val == 'Critical': return 'background-color: #ffcccc; color: black; font-weight: bold;'
                elif val == 'High': return 'background-color: #ffe6cc; color: black;'
                return ''
                
            st.dataframe(df_schedule.style.map(highlight_urgency, subset=['Priority']), use_container_width=True)

        
        # 2. Extensions: Capacity Validation & Recommendation Warnings
        st.subheader("⚠️ Capacity Insights & Conflict Resolution")
        col1, col2 = st.columns(2)
        
        with col1:
            total_task_demand = tasks['Effort Required (Hours)'].sum()
            st.metric("Total Load Demand", f"{total_task_demand} Hours")
            st.metric("Total Available Bandwidth", f"{total_available_hours} Hours")
            
            if total_task_demand > total_available_hours:
                st.warning(f"🚨 **Workload Warning**: Overloaded! Demand exceeds limit by {total_task_demand - total_available_hours} hours.")
            else:
                st.info("✅ Ideal Load: Your schedule fits nicely within constraints.")
                
        with col2:
            if dropped_tasks:
                st.error("❌ Backlogged/Deferred Tasks (Insufficient Bandwidth)")
                st.dataframe(pd.DataFrame(dropped_tasks), use_container_width=True)
                st.markdown("**Personalized Recommendation**: Delegate or reduce scope on lower-priority items. Alternatively, adjust your configuration to increase daily available hours.")
            else:
                st.success("🎉 No tasks dropped. Efficiently optimized distribution achieved.")

        # 3. Visual Layout Analytics
        st.subheader("📊 Workload Metrics Visualization")
        fig, ax = plt.subplots(figsize=(6, 2.5))
        colors = ['#4CAF50' if t <= total_available_hours else '#FF5722' for t in [accumulated_hours, total_task_demand]]
        ax.barh(['Scheduled Focus', 'Total Requested Load'], [accumulated_hours, total_task_demand], color=['#2196F3', '#FF9800'])
        ax.axvline(total_available_hours, color='red', linestyle='--', label='Max Bandwidth Threshold')
        ax.set_xlabel('Hours')
        ax.legend()
        st.pyplot(fig)
