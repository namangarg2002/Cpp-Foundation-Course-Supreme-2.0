#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void printArray(int arr[], int size, int index){
    if(index >= size) return;
    cout<<arr[index]<<" ";
    printArray(arr, size, index+1);
}
bool searchArray(int arr[], int size, int target, int index){
    if(index >= size){
        return false;
    }
    if(arr[index] == target){
        return true;
    }
    return searchArray(arr, size, target, index+1);
}

void findMin(int arr[], int size, int index, int &mini){
    // base case
    if(index>=size){
        return;
    }
    // processing
    mini = min(mini, arr[index]);
    // recursicve call
    findMin(arr,size, index+1, mini);
}
void solve(int arr[], int size, int index, vector<int> &vect){
    if(index>=size){
        return;
    }
    if(arr[index]%2==0){
        vect.push_back(arr[index]);
    }
    solve(arr,size, index+1, vect);
}
void findMax(int arr[], int size, int index, int &maxi){
    if(index>=size) return;
    maxi = max(maxi, arr[index]);
    findMax(arr,size, index+1, maxi);
}
void doubleValue(int arr[], int size, int index){
    if(index >= size) return;
    arr[index] = 2*arr[index];
    doubleValue(arr, size, index+1);
}

int validIndex(int arr[], int size, int index, int target){
    if(index >= size) return -1;

    if(arr[index]==target){
        return index;
    }
    return validIndex(arr, size, index+1, target);
}

void indexOcurence(int arr[], int size, int index, int target){
    if(index >= size) return;
    if(arr[index]==target){
        cout<< index << " ";
    }
    return indexOcurence(arr,size ,index+1 ,target);
}

vector<int> find(int arr[], int size, int index, int target){
    vector<int> ans;
    if(index >= target) return ans;
    if(arr[index]==target){
        ans.push_back(index);
    }
    vector<int> nextResults =  find(arr, size, index+1, target);
    for(int i=0; i<nextResults.size(); i++){
        ans.push_back(nextResults[i]);
    }
    return ans;
}
void printDigit(int num){
    if(num==0) return;
    int digit = num % 10;
    num = num / 10;

    printDigit(num);
    cout<<digit<<endl;

}
void printDigits(int num, vector<int> &ans){
    if(num==0) return;
    int digit = num % 10;
    num = num / 10;

    printDigits(num, ans);
    ans.push_back(digit);

}
void reversePrintDigits(int num, vector<int> &ans){
    if(num==0) return;
    int digit = num % 10;
    num = num / 10;

    ans.push_back(digit);
    reversePrintDigits(num, ans);
}
int main(){
    // int arr[] = {10,20,30,40,50};
    // int size = 5;
    // int index = 0;
    // int target = 50;
    // printArray(arr,size, index);
    // cout<<"Target found or not : "<<searchArray(arr,size,target, index);
    // int mini = INT_MAX;
    // findMin(arr, size, index, mini);
    // cout<<"Minimum number in array: "<<mini<<endl;

    // int arr[] = {10,11,12,13,14};
    // int size = 5;
    // int index = 0;
    // vector<int> vect;
    // solve(arr, size, index, vect);
    // for(int i=0; i<vect.size(); i++){
    //     cout<<vect[i]<<" ";
    // }

    // int arr[] = {10,20,30,40,50};
    // int size = 5;
    // int index = 0;
    // // int maxi = INT_MIN;
    // // findMax(arr,size, index, maxi);
    // // cout<<"MAximum of these numbers is : "<<maxi<<endl;
    // doubleValue(arr,size,index);
    // for(auto num: arr){
    //     cout<<num<<" ";
    // }

    // int arr[] = {10,20,30,40,50};
    // int size = 5;
    // int index = 0;
    // int target = 50;
    // int ans = validIndex(arr,size,index, target);
    // cout<<ans;

    // int arr[] = {10,20,10,10,30,40};
    // int size = 6;
    // int index = 0;
    // int target = 10;
    // // indexOcurence(arr,size,index, target);
    // vector<int> ans = find(arr,size,index,target);
    // for(int i=0; i<ans.size(); i++){
    //     cout<<ans[i]<<" ";
    // }

    int num = 4215;
    // printDigit(num);
    vector<int> ans;
    // printDigits(num, ans);
    reversePrintDigits(num, ans);
    for(auto num:ans){
        cout<<num<<endl;
    }

    return 0;
}