#include <stdio.h>

int main() {
    int num;
    int d1, d2, d3, d4;
    int temp;
    int ascending_num, descending_num;

    // Request a 4-digit number from the user
    printf("Enter a four-digit number: ");
    if (scanf("%d", &num) != 1 || num < 1000 || num > 9999) {
        printf("Error: Please enter a valid 4-digit number.\n");
        return 1;
    }

    // Extract each digit into separate variables
    while(num != 6174){
    d1 = num / 1000;       // Thousands digit
    d2 = (num / 100) % 10; // Hundreds digit
    d3 = (num / 10) % 10;  // Tens digit
    d4 = num % 10;         // Units digit

    // Sort separate variables so d1 <= d2 <= d3 <= d4
    if (d1 > d2) { temp = d1; d1 = d2; d2 = temp; }
    if (d1 > d3) { temp = d1; d1 = d3; d3 = temp; }
    if (d1 > d4) { temp = d1; d1 = d4; d4 = temp; }
    if (d2 > d3) { temp = d2; d2 = d3; d3 = temp; }
    if (d2 > d4) { temp = d2; d2 = d4; d4 = temp; }
    if (d3 > d4) { temp = d3; d3 = d4; d4 = temp; }

    // Combine individual digits into single integer variables
    ascending_num = (d1 * 1000) + (d2 * 100) + (d3 * 10) + d4;
    descending_num = (d4 * 1000) + (d3 * 100) + (d2 * 10) + d1;

    // Display the final combined variables
    // Note: %04d preserves leading zeros (e.g., 0123 instead of 123)
    //printf("Ascending single variable value:  %04d\n", ascending_num);
    //printf("Descending single variable value: %04d\n", descending_num);
    num = descending_num - ascending_num;
    printf("num is %d\n",num);
    if(num == 6174){printf("you successfully reached karprekar constant 6174");}
    
    }

    return 0;
}
