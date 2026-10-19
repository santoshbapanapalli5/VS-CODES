#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0;i < N;i++){
        cin >> arr[i];
        if(arr[i] < 0){
            arr[i] = arr[i] * (-1);
        }
        
    }
    int small = arr[0];
    
    for(int i = 0;i < N;i++){
        if(arr[i + 1] > arr[i - 1]){
            small = arr[i - 1];
        }
    }
    cout <<small;
}