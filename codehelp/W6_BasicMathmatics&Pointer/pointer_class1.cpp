#include<iostream>
using namespace std;

int main(){
    // int a = 5;
    // cout<<a<<endl;
    // cout<<"address of a : "<<&a<<endl;

    // // pointer createion
    // int* ptr = &a;
    // // accessing value stored at address stored in ptr
    // cout<<ptr<<endl;
    // cout<<"Accessing : "<<*ptr<<endl;
    // cout<<&ptr<<endl;
    // return 0;

    // int a = 5;
    // int* ptr = &a;
    // cout<<sizeof(ptr)<<endl;

    // char ch = 'K';
    // char* cptr = &ch;
    // cout<<sizeof(cptr)<<endl;

    // long lachi = 10;
    // long* lptr = &lachi;
    // cout<<sizeof(lptr)<<endl; 

    // int* ptr = nullptr;
    // cout<<*ptr<<endl;

    // int a = 5;
    // int* p = &a;

    // p = p + 1;
    // cout<<*p;

    // int arr[5]={1,2,3,4,5};
    // arr = arr + 1;

    // int arr[4]={1,2,3,4};
    // int* p = arr;
    // int *q  = arr + 1;
    // // cout<<*(q+4);
    // cout<<p<<endl;

    // char ch[50] = "love";
    // char* cptr = ch;
    // cout<<cptr;

    char ch = 'a';
    char* cptr = &ch;
    cout<<cptr;
    cout<<endl;
    cout<<sizeof(cptr);
}