#include<iostream>
using namespace std;

int searchNearlySorted(int arr[], int n, int target){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(mid-1>=0 && target==arr[mid-1]){
            return mid-1;
        }else if(target==arr[mid]){
            return mid;
        }else if(mid+1<n && target==arr[mid+1]){
            return mid+1;
        }else if(target > arr[mid]){
            // right shift
            s = mid + 2;
        }else{
            // left shift
            e = mid - 2;
        }
        mid = s + (e-s)/2; 
    }
    return -1;
}
int main(){
    int arr[] = {20,10,30,50,40,70,60};
    int n = 7;
    int target = 40;
    
    int targetIndex = searchNearlySorted(arr, n, target);
    if(targetIndex == -1){
        cout<<"Element Not found"<<endl;
    }else{
        cout<<"Element found at: "<<targetIndex<<endl;
    }
    return 0;
}