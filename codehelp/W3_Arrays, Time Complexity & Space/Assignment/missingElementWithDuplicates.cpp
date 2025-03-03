#include<iostream>
using namespace std;

void findMissing(int *arr, int n){
    // // visited Approach
    // for(int i=0; i<n; i++){
    //     int index = abs(arr[i]);
    //     if(arr[index - 1] > 0){
    //         arr[index - 1] *= -1;
    //     }
    // }

    // // used to show the array with negative marking
    // // for(int i=0; i<n; i++){
    // //     cout<<arr[i]<<" ";
    // // }

    // // Used to show the number which is missing
    // for(int i=0; i<n; i++){
    //     if(arr[i]>=0){
    //         cout<<i+1<<" ";
    //     }
    // }

    // Sorting + Swapping Method
    int i=0;
    while(i<n){
        int index = arr[i]-1;
        if(arr[i] != arr[index]){
            swap(arr[i], arr[index]);
        }
        else{
            i++;
        }
    }
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    for(int i=0; i<n; i++){
        if(i+1 != arr[i]){
            cout<<i+1<<" ";
        }
    }
}
int main(){
    int n;
    int arr[] = {1,3,5,3,4};
    n = sizeof(arr)/sizeof(int);
    findMissing(arr, n);
    return 0;
}