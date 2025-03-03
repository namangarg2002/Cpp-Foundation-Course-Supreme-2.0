#include<iostream>
using namespace std;

void solve(int *arr, int size){
    // cout<<"Size of an array 1: "<<sizeof(arr)<<endl;
    cout<<"Inside solve -> arr "<<arr <<endl;
    cout<<"Inside solve -> &arr "<<&arr <<endl;
}
void solve1(int arr[]){
    *arr = *arr + 1;
}

// // Pass by Value 
// void solve2(int *p){
//     p = p + 1;
// }

// Pass by Reference
void solve2(int* &p){
    p = p + 1;
}

int main(){
    // // int arr[5] = {1,2,3,4,5};

    // // // pointer to an array
    // // // int* ptr = arr;

    // // // pointer to an array
    // // int (*ptr)[5] = &arr;
    // // cout<<*(*ptr)<<endl;

    // char ch[20] = "naman";
    // // char* cptr = ch;
    // char (*cptr)[20] = &ch;
    // cout<<*(*cptr+2)<<endl;

    // int arr[] = {10,20,30,40,50};
    // // cout<<"Size of an array 0: "<<sizeof(arr)<<endl;
    // solve(arr,5);
    // cout<<"Inside main -> arr "<<arr <<endl;
    // cout<<"Inside main -> &arr "<<&arr <<endl;

    // int arr[] = {10,20,30};
    // solve1(arr);
    // for(int i=0; i<3; i++){
    //     cout<<arr[i];
    //     if(i!=2){
    //         cout<<", ";
    //     }
    // }
    // cout<<endl;

    int a = 5;
    int *p = &a;
    cout<<"Value before function : "<<endl;
    cout<<"Value of p-> "<<p<<endl;
    cout<<"Value of &p-> "<<&p<<endl;
    cout<<"Value of *p-> "<<*p<<endl;

    solve2(p);
    cout<<"Value After function : "<<endl;
    cout<<"Value of p-> "<<p<<endl;
    cout<<"Value of &p-> "<<&p<<endl;
    cout<<"Value of *p-> "<<*p<<endl;
    return 0;
}