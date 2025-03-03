#include<iostream>

using namespace std;

void shiftnegativebyleftside(int arr[], int n){
    int index = 0;
    int left = 0;
    int right = n-1;

    while(index<=right){
        if(arr[index]<0){
            swap(arr[index], arr[left]);
            index++;
            left++;
        }else if(arr[index]>0){
            swap(arr[index], arr[right]);
            right--;
        }else{
            index++;
        }
    }
}
int main(){
    int arr[] = {1,2,-3,4,-5,6};
    int n = sizeof(arr)/sizeof(int);
    
    shiftnegativebyleftside(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}