#include<iostream>

using namespace std;
 int main(){
    int N;
    cout<<"Enter the number : ";
    cin>>N;

    bool is_Prime = true;

    for(int i=2; i<=N/2;i++){
        if (N % i == 0){
            is_Prime = false;
        }
    }

    if (is_Prime){
        cout<<"Number is Prime"<<endl;
    }else{
        cout<<"Number is not Prime"<<endl;
    }
    return 0;
 }