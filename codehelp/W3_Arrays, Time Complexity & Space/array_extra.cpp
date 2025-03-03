#include<iostream>
using namespace std;

void sort(int arr[], int n){
    int j = 0;
    // j-> mememory block -> jaha pr main negative number store kar sakta hu

    for(int index=0; index<n; index++){
        if(arr[index]<0){
            swap(arr[index], arr[j]);
            j++;
        }
    }
}

void sortColor(int arr[], int n){
    int index = 0;
    int left = 0;
    int right = n-1;
    while(index <= right){
        if(arr[index] == 0){
            swap(arr[index], arr[left]);
            left++;
            index++;
        }else if(arr[index]==2){
            swap(arr[index], arr[right]);
            right--;
        }else{
            index++;
        }
    }
}

void rotateArray(int arr[], int n, int k){
    int rotated[n];
    for(int index=0; index<n; index++){
        int newIndex = (index + k)%n;
        // (0+2)%6 = 2%6 = 2 = arr[newarray] = arr[2] = original array value at index 2
        rotated[newIndex] = arr[index];
    }
    // here we assign all the rotated array value to original array
    for(int index=0; index<n; index++){
        arr[index] = rotated[index];
    }
    
}
void missingNumber(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + arr[i];
    }
    int totalsum = ((n)*(n+1))/2;
    int ans = totalsum - sum;
    cout<<ans<<endl;
}



int main(){

    // problem - Negative left side positive Right side
    // int arr[7] = {23,-7,12,-10,-11,40,60};
    // int n = 7;
    // sort(arr, n);
    // cout<<"Printing the array "<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<< " ";
    // }

    // leetcode problem (Sort Color)

    // int arr[8] = {1,0,2,2,1,0,1,0};
    // int n = 8;
    // sortColor(arr, n);
    // cout<<"Printing the Sorted array "<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<< " ";
    // }

    // leetcode problem (Rotate Array)
    
    // int arr[6] = {10,20,30,40,50,60};
    // int n = 6;
    // int k = 2;
    // rotateArray(arr, n, k);
    // cout<<"Printing the Sorted array "<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<< " ";
    // }

    // leetcode problem (Missing Number)

    // int arr[3] = {3,0,1};
    // int n = 3;
    // missingNumber(arr, n);

    // Leetcode problem(Row with Maximum Ones)

    int arr[][] = 

    
    return 0;
}