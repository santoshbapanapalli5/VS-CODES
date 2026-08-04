#include <stdio.h>

#define MAX_NUM 50
#define GRID_SIZE 5

// Helper function to find numbers for a grid and store them in an array
void generate_grid(int g, int grid_nums[GRID_SIZE * GRID_SIZE]) {
    int count = 0;
    int num = 1;
    
    while (count < GRID_SIZE * GRID_SIZE) {
        if ((num & (1 << g)) && num <= MAX_NUM) {
            grid_nums[count] = num;
            count++;
        } else if (num > MAX_NUM) {
            grid_nums[count] = -1; // Use -1 to represent an empty slot
            count++;
        }
        num++;
    }
}


int main() {
    int grids[6][GRID_SIZE * GRID_SIZE];
    printf("think a number from 1 to 50 and follow procedure\n\n\n");
    
    // 1. Generate data for all 6 grids
    for (int g = 0; g < 6; g++) {
        generate_grid(g, grids[g]);
    }
    
    // 2. Print pairs of grids side-by-side (3 macro-rows total)
    for (int pair = 0; pair < 3; pair++) {
        int g1 = pair * 2;     // Left grid (0, 2, 4)
        int g2 = pair * 2 + 1; // Right grid (1, 3, 5)
        
        // Print the headers for the two side-by-side grids
        printf("--- Grid %d (Start: %02d) ---        --- Grid %d (Start: %02d) ---\n", 
               g1 + 1, 1 << g1, g2 + 1, 1 << g2);
        
        // Print row by row for both grids simultaneously
        for (int r = 0; r < GRID_SIZE; r++) {
            
            // Print 5 elements of the left grid row
            for (int c = 0; c < GRID_SIZE; c++) {
                int val1 = grids[g1][r * GRID_SIZE + c];
                if (val1 == -1) printf(".. ");
                else printf("%02d ", val1);
            }
            
            // Gap between the two side-by-side grids
            printf("       "); 
            
            // Print 5 elements of the right grid row
            for (int c = 0; c < GRID_SIZE; c++) {
                int val2 = grids[g2][r * GRID_SIZE + c];
                if (val2 == -1) printf(".. ");
                else printf("%02d ", val2);
            }
            
            printf("\n"); // Move to the next horizontal row of numbers
        }
        printf("\n"); // Double space between the sets of blocks
    }
    int a,b,d = 0;
    for(a = 1;a <= 6;a++){
    printf("please enter 1 if num is present and 0 if not present in grid %d  : ",a);
    scanf("%d", &b);
    if(b == 1 && a == 1){
        d = d + 1;
    }
    else if(b == 1 && a == 2){
        d = d + 2;
    }
    else if(b == 1 && a == 3){
        d = d + 4;
    }
    else if(b == 1 && a == 4){
        d = d + 8;
    }
    else if(b == 1 && a == 5){
        d = d + 16;
    }
    else if(b == 1 && a == 6){
        d = d + 32;
    }
    }
    printf("\n\nyour num is %d",d );
    return 0;
}