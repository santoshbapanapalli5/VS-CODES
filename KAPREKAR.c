#include <stdio.h>

int main() {
    int num;
    int d1, d2, d3, d4;
    int temp;
    int ascending_num, descending_num;

    
    printf("Enter a four-digit number: ");
    if (scanf("%d", &num) != 1 || num < 1000 || num > 9999) {
        printf("Error: Please enter a valid 4-digit number.\n");
        return 1;
    }

    
    while(num != 6174){
    d1 = num / 1000;       
    d2 = (num / 100) % 10; 
    d3 = (num / 10) % 10;  
    d4 = num % 10;         

    
    if (d1 > d2) { temp = d1; d1 = d2; d2 = temp; }
    if (d1 > d3) { temp = d1; d1 = d3; d3 = temp; }
    if (d1 > d4) { temp = d1; d1 = d4; d4 = temp; }
    if (d2 > d3) { temp = d2; d2 = d3; d3 = temp; }
    if (d2 > d4) { temp = d2; d2 = d4; d4 = temp; }
    if (d3 > d4) { temp = d3; d3 = d4; d4 = temp; }

    
    ascending_num = (d1 * 1000) + (d2 * 100) + (d3 * 10) + d4;
    descending_num = (d4 * 1000) + (d3 * 100) + (d2 * 10) + d1;

    
    num = descending_num - ascending_num;
    printf("num is %d\n",num);
    if(num == 6174){printf("you successfully reached kaprekar constant 6174");}
    
    }

    return 0;
}
