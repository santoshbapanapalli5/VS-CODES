#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    int choice, amount, balance = 0, total_deposits = 0, total_withdrawals = 0;
    int continue_choice;

    
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    
    while(1) {
        
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        printf("--- Welcome to Bank of Santosh ---\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Show My Balance\n");
        printf("4. Exit\n");
        printf("5. See Total Deposits\n");
        printf("6. See Total Withdrawals\n");
        printf("Please select an option (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input type!\n");
            break;
        }

        if (choice == 1) {
            printf("Enter the money you want to deposit: ₹");
            scanf("%d", &amount);
            balance += amount;
            total_deposits += amount;
            printf("Your present balance is: ₹%d\nThank you for depositing money!\n", balance);
        } 
        else if (choice == 2) {
            printf("Enter the money you want to withdraw: ₹");
            scanf("%d", &amount);
            if (balance >= amount) {
                balance -= amount;
                total_withdrawals += amount;
                printf("Your present balance is: ₹%d\nThank you, please visit again.\n", balance);
            } else {
                printf("Error: Insufficient balance to withdraw!\n");
            }
        } 
        else if (choice == 3) {
            printf("Your present account balance is: ₹%d\n", balance);
        } 
        else if (choice == 4) {
            printf("Thank you for using Bank of Santosh. Goodbye!\n");
            break;
        } 
        else if (choice == 5) {
            printf("Your total deposits during this session: ₹%d\n", total_deposits);
        } 
        else if (choice == 6) {
            printf("Your total withdrawals during this session: ₹%d\n", total_withdrawals);
        } 
        else {
            printf("Invalid selection! Please choose an option between 1 and 6.\n");
        }

        if (choice != 4) {
            printf("\nDo you want to perform another transaction? (1.Yes / 2.No): ");
            scanf("%d", &continue_choice);
            if (continue_choice == 2) {
                printf("Thank you for using Bank of Santosh. Goodbye!\n");
                break;
            }
        }
    }

    return 0;
}
