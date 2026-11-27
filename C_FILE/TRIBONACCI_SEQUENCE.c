#include <stdio.h>
int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    int a[n];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    printf("%d, %d, %d", a[0], a[1], a[2]);
    for (int i = 3; i < n; i++) {
        a[i] = a[i-1] + a[i-2] + a[i-3]; 
        printf(", %d", a[i]);
    }
    printf("\n");
    return 0;
}