#include<iostream>
using namespace std;

// int incrementBy1(int n){
//     n = n + 1;
//     return n;
// }

void incrementBy1(int &k){
    k = k + 1;
}

int main(){

    // Reference variable


    // // int n = 5;
    // // int &k = n;
    // // int &c = n;
    // // cout<<n<<endl;
    // // cout<<k<<endl;
    // // cout<<c<<endl;

    // int n = 5;
    // int &k = n;
    // int &c = n;
    // cout<<"n : "<<n<<endl;
    // cout<<"k : "<<k<<endl;
    // cout<<"c : "<<c<<endl;

    // k++;

    // cout<<"n : "<<n<<endl;
    // cout<<"k : "<<k<<endl;
    // cout<<"c : "<<c<<endl;

    // int n;
    // cin>>n;
    // n = incrementBy1(n);
    // cout<<n<<endl;

    int n;
    cin>>n;
    incrementBy1(n);
    cout<<"n : "<<n<<endl;

    return 0;
}