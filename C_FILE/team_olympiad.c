#include <stdio.h>
int main(){
    int one = 0;
    int two = 0;
    int three = 0;
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0;i < n;i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0;i < n;i++){
        if(arr[i] == 1){
            one++;
        }
        if(arr[i] == 2){
            two++;
        }
        if(arr[i] == 3){
            three++;
        }
    }
    int max_teams = 0;
    if((one > 0) && (two > 0) && (three > 0)){
        if(((one <= two) && (one <= three))){
            max_teams = one;
        }
        if(((two <= three) && (two <= one))){
            max_teams = two;
        }
        if(((three <= one) && (three <= two))){
            max_teams = three;
        }
    }
    printf("%d\n",max_teams);

    int j = 0, k = 0, l = 0;
    int one_n[n],two_n[n],three_n[n];
    for(int i = 0;i < n;i++){
        if(arr[i] == 1){
            one_n[j] = i;
            j++;
        }
        if(arr[i] == 2){
            two_n[k] = i;
            k++;
        }
        if(arr[i] == 3){
            three_n[l] = i;
            l++;
        }
    }
    for(int i = 0;i < max_teams;i++){
        printf("%d %d %d\n",one_n[i]+1,two_n[i]+1,three_n[i]+1);
    }
    return 0;
}
