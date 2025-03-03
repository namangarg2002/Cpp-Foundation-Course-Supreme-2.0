#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int start = 0;
    int end = n-1;
    int mid = (start + end)/2;

    while(start <= end){
        // found
        if(arr[mid]==target){
            return mid;
        }else if(target>arr[mid]){
            // moving to right
            start = mid + 1;
        }else{
            // moving to left
            end = mid - 1;
        }
        // update mid value
        mid = (start + end)/2;
    }
    return -1;
}

int firstOccurence(int arr[], int n, int target){
    int s = 0;
    int e = n-1;
    int mid = s/2 + e/2;
    int ans = -1;

    while(s<=e){
        if(arr[mid]==target){
            ans = mid;
            e = mid - 1;
        }else if(target > arr[mid]){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
        mid = (s+e)/2;
    }
    return ans;
}

int lastOccurence(int arr[], int n, int target){
    int s = 0, e = n-1;
    int mid = s/2 + e/2;
    int ans = -1;

    while(s<=e){
        if(target==arr[mid]){
            ans = mid;
            s = mid + 1;
        }else if(target>arr[mid]){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
        mid = (s + e)/2;
    }
    return ans;
}
int totalOccurence(int arr[], int n, int target){
    int firstOcc = firstOccurence(arr, n, target);
    int lastOcc = lastOccurence(arr, n, target);
    int total = lastOcc - firstOcc + 1;
    return total;
}

int findMissing(int arr[], int n){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        int diff = arr[mid] - mid;

        if(diff==1){
            s = mid + 1;
        }else{
            ans = mid;
            e = mid - 1;
        }
        mid = s + (e-s)/2;
        if(ans+1==0){
            return n+1;
        }
    }
    return ans+1;
}


int main(){
    // int arr[] = {10,20,30,40,50,60,70,80,90};
    // int target = 90;
    // int n = 9;

    // int ansIndex = binarySearch(arr, n, target);
    // if(ansIndex == -1){
    //     cout<<"Element Not Found"<<endl;
    // }else{
    //     cout<<"Element Found at Index: "<<ansIndex<<endl;
    // }

    // int arr[] = {10,20,30,30,30,30,30,30,40,50};
    // int target = 30;
    // int n = 10;
    // int ansIndex = firstOccurence(arr, n, target);
    // int ansIndex1 = lastOccurence(arr, n, target);
    // int ansIndex2 = totalOccurence(arr, n, target);
    // cout<<ansIndex;
    // cout<<ansIndex1;
    // cout<<ansIndex2;

    int arr[] = {1,2,3,4,5,6,7,8};
    int n = 8;
    int missing = findMissing(arr, n);
    cout<<missing<<endl;

    return 0;
}