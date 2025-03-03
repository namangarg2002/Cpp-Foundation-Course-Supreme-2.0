#include<iostream>
#include<vector>
using namespace std;

bool sorted(int arr[], int size, int index){
    if(index>=size || index<=0) return true;
    if(arr[index]>arr[index-1]){
        bool aageKaAns = sorted(arr, size, index+1);
        return aageKaAns;
    }else{
        return false;
    }
}
int binSearch(int arr[], int s , int e, int target){
    // base case
    if(s>e){
        // element not found 
        return -1;
    }
    int mid = s + (e-s)/2;
    if(arr[mid]==target){
        return mid;
    }if(arr[mid]<target){
        return binSearch(arr, mid+1, e, target);
    }else{
        return binSearch(arr, s, mid-1, target);
    }
}

void findSubSequences(string str, string output, int index, vector<string> &ans){
    // base Case
    // ans joh hai vo ouput string m build ho chuka hai
    // print kardo
    if(index >= str.length()){
        ans.push_back(output);
        return;
    }
    char ch = str[index];
    // exlude
    findSubSequences(str, output, index+1, ans);
    // include
    // output string me ch chracter ko include kardo
    output.push_back(ch);
    findSubSequences(str, output, index+1, ans);
}

int main(){
    // int arr[] = {10};
    // int size = 1;
    // int index = 1;
    // bool isSorted = sorted(arr, size, index);
    // if(isSorted)
    //     cout<<"Array is Sorted "<<endl;
    // else
    //     cout<<"Array is Not Sorted"<<endl;

    // int arr[] = {10,20,30,40,50,60,70,80};
    // int size = 8;
    // int start = 0;
    // int end = size - 1;

    // int target = 80;

    // int foundIndex = binSearch(arr, start, end, target);
    // if(foundIndex != -1){
    //     cout<<"Target found at : "<<foundIndex<<endl;
    // }else{
    //     cout<<"Target not found"<<endl;
    // }


    string str = "abc";
    string output = "";
    int index = 0;
    vector<string> ans;
    findSubSequences(str, output,index, ans);
    for(auto num: ans){
        cout<<"->"<<num<<endl;
    }


    return 0;
}
