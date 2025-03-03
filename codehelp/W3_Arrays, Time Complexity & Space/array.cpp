#include<iostream>
#include<limits.h>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool linearSearch(int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;

}

void countZeroOne(int arr[], int size){
    int zeroCount = 0;
    int oneCount = 0;
    for(int i=0; i<size ; i++){
        if (arr[i]==0){
            zeroCount++;
        }else{
            oneCount++;
        }
    }
    cout<<"0's are : "<<zeroCount<<endl; 
    cout<<"1's are : "<<oneCount<<endl; 
}

void minNumber(int arr[], int size){
    int minAns = INT_MAX;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
        if(arr[i]<minAns){
            minAns = arr[i];
        }
    }
    cout<<"\nMinimum of these number is "<<minAns;
}

void reverse(int arr[], int size){
    cout<<"Array is : ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nReversed Array is : ";
    for(int i=size-1; i>=0; i--){
        cout<<arr[i]<<" ";  
    }
}

void reverseSwap(int arr[], int size){
    int left = 0;
    int right = size-1;
    while(left<=right){
        swap(arr[left],arr[right]);
        left++;
        right--;
    }
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

}

void extremePrintArray(int arr[], int size){
    int left = 0;
    int right = size-1;
    while(left<=right){
        if(left==right){
            cout<<arr[left]<<endl;
        }else{
            cout<<arr[left]<<" ";
            cout<<arr[right]<< " ";
        }
        left++;
        right--;
    }
}

int main(){
    // int arr[10];
    // char ch[102];
    // bool flags[223];
    // cout<<"Array is created successfully"<<endl;

    // int a = 5;
    // cout<< "Address of a : "<< &a <<endl;
    // cout<< "Size of a : "<< sizeof(a) <<endl;

    // int arr[10];
    // cout<<"Address of arr is : "<<&arr <<endl;
    // cout<<"Size of arr is : "<<sizeof(arr) <<endl;

    // int arr[] = {2, 3, 4, 5, 6};

    // int brr[5] = {2, 3, 4, 5, 6};

    // int crr[5] = {2, 3};

    // int drr[2] = {2, 3, 4, 5, 6};

    // int arr[5] = {5, 4, 3, 2, 1};
    // cout<<arr[3]<<endl;
    // cout<<arr[2]<<endl;

    // int brr[5] = {5, 4, 3, 2, 1};

    // int n = 5;
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<< " ";
    // }

    // int arr[5];

    // int n = 5;
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }
    // for(int i=n-1; i>=0; i--){
    //     cout<<arr[i]<<" ";
    // }

    // Problem statement 1

    // int arr[10];
    // int n = 10;
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }
    // cout<<"Printing after taking input"<<endl;

    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }

    // cout<<"\nDoubles : \n";
    // for(int i=0; i<n; i++){
    //     arr[i] = 2*arr[i];
    // }
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }

    // Problem statement 1

    // int arr[5];

    // int n = 5;
    // cout<<"Enter the input : "<<endl;
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }
    // int sum = 0;
    // for(int i=0; i<n; i++){
    //     sum = sum + arr[i];
    // }
    // cout<<"Sum is "<<sum<<endl;

    // int arr[6] = {2, 4, 6, 8, 10, 12};
    // int n = 6;
    // int target = 10;
    // bool flag = 0;
    // for(int i=0 ; i<n; i++){
    //     if(arr[i]==target){
    //         flag = 1;
    //         break;
    //     }
    // }
    // if (flag == 1){
    //     cout<<"Target found";
    // }else{
    //     cout<<"Target not found";
    // }

    // int arr[5] = {2, 4, 6, 8, 10};
    // int size = 5;
    // printArray(arr, size);

    // Linear search through array and function

    // int arr[5] = {2,4,6,8,10} ;
    // int size = 5;
    // int target = 10;

    // bool ans = linearSearch(arr, size, target);
    // if(ans == 1){
    //     cout<<"Target found"<<endl;
    // }else{
    //     cout<<"Target not found"<<endl;
    // }

    // Probem - Count 0's and 1's in an array

    // int arr[5] = {0,1,1,0,0};
    // int s = 5;
    // countZeroOne(arr, s);

    // Range of Integer

    // cout<<INT_MAX<<endl;
    // cout<<INT_MIN<<endl;

    // Minimum of all numbers

    // int arr[8] = {20,0,4,15,2,6,8,11};
    // int size = 8;
    // minNumber(arr, size);

    // Reverse of Array using simple method 

    // int arr[6] = {10,20,30,40,50,60};
    // int size = 6;
    // reverse(arr, size);

    // Reverse of Array using swap method 

    // int arr[7] = {10,20,30,40,50,60,70};
    // int size = 7;
    // reverseSwap(arr, size);

    // Extreme print in an array

    int arr[6] = {10,20,30,40,50,60};
    int size = 6;
    extremePrintArray(arr, size);

    return 0;
}  