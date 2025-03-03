#include<iostream>
using namespace std;

int bs(int arr[],int &s, int &e, int &x){
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid]==x){
            return mid;
        }else if(x>arr[mid]){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return -1;
}

int unboundedSearch(int arr[], int x){
    int i = 0;
    int j = 1;
    while(arr[j]<x){
        i=j;
        j=j*2;
    }
    return bs(arr, i, j, x);
}

int main(){
    int arr[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int x = 10;
    int ans = unboundedSearch(arr, x);
    cout<<ans<<endl;
    return 0;
}