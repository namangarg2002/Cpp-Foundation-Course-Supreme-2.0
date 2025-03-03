#include<iostream>
using namespace std;

int findOddOccuringElement(int arr[], int n){
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        // single element
        if(e==s){
            return s;
        }
        if(mid & 1){    // odd number
            if(arr[mid]==arr[mid-1]){
                // right shift
                s = mid + 1;
            }else{
                // left shift
                e = mid - 1;
            }
        }else{
            if(arr[mid]==arr[mid+1]){
                // right shift
                s = mid + 2;
            }else{
                mid = ans;
                e = mid;
            }

        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    int arr[] = {10,10,2,2,5,5,2,5,5,20,20,11,11,10,10};
    int n = 15;

    int index = findOddOccuringElement(arr, n);
    cout<<arr[index]<<endl;
    
    return 0;
}