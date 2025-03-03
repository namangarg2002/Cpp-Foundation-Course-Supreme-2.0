#include<iostream>
#include<vector>
using namespace std;

// void fun(int a[], int n){
//     cout<<"Elements are : "<<endl;
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<endl;
//     }
// }

// void print(vector<int> v){
//     int size = v.size();
//     cout<<"Printing vector is : \n";
//     for(int i=0; i<size; i++){
//         // cout<<v[i]<<endl;
//         cout<<v.at(i)<<" "; // same as previous line which means print vector value at ith index
//     }
// }

void print2(vector<int> v){
    cout<<"Printing vector method 2"<<endl;
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    // // Static Memory Allocation
    // // int arr[5] = {1,2,3,4,5};
    // // fun(arr, 5); 

    // // Dynamic Memory Allocation
    // int n;
    // cin>>n;
    // int *arr = new int[n]; // Each element would be 0 or garbage

    // // Taking n elements input and inserting in array
    // for(int i=0; i<n; i++){
    //     int data;
    //     cin>>data;
    //     arr[i] = data;
    // }

    // // let me try to insert more items
    // arr[n] = 80; 
    // fun(arr, n);


    // In Vector don't need to tell size of vector
    // just keep inserting, i will manage the aloocations.

    // vector<int> v;

    // // PUSH -> insert
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // print(v);

    // // POP -> delete -> from End
    // // 1 -> 2 -> 3-> then 3 will go first thewn 2 then 1 
    // v.pop_back();
    // print(v);

    // v.pop_back();
    // print(v);

    // // insert data from user

    // vector<int> v;

    // int n;
    // cin>>n;
    // for(int i=0; i<n; i++){
    //     int d;
    //     cin>>d;
    //     v.push_back(d);
    // }
    // // for(int i=0; i<n+1; i++){
    // //     v.push_back(6);
    // // }
    // v.push_back(6);
    // v.push_back(7);
    // print(v);

    // // I want to clear all data from vector 

    // vector<int> v;

    // int n;
    // cin>>n;
    // for(int i=0; i<n; i++){
    //     int d;
    //     cin>>d;
    //     v.push_back(d);
    // }
    // // for(int i=0; i<n+1; i++){
    // //     v.push_back(6);
    // // }
    // v.push_back(6);
    // v.push_back(7);
    // print(v);

    // // clear data
    // v.clear();
    // v.push_back(10);
    // print(v);

    // vector<int> arr;

    // vector<int> arr2(5, -1);
    // print(arr2);

    // vector<int>arr3 = {1,2,3,4,5};
    // print(arr3);

    // vector<int>arr4{1,2,3,4,5};
    // print(arr4);

    // vector<int>arr5{1,2,3,4,5};
    // vector<int>arr6(arr5);
    // print(arr6);

    // Front and last element of an vector

    // vector<char> v;
    // v.push_back('a');
    // v.push_back('b');
    // v.push_back('c');
    // v.push_back('d');

    // // cout<<"Front element : "<<v[0]<<endl;
    // cout<<"Front element : "<<v.front()<<endl;
    // // cout<<"End element : "<<v[v.size()-1]<<endl;
    // cout<<"End element : "<<v.back()<<endl;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    print2(v);

    


    
    return 0;
}