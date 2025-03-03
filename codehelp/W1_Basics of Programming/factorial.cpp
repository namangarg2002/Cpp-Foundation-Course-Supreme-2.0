#include<iostream>

using namespace std;

int main(){
    int N, fact = 1;
    cin>>N;
    for(int i = N; i>=1; i--){
        fact = fact*i;
    }
    cout<<fact<<endl;
    return 0;

}