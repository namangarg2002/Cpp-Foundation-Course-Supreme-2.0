#include<iostream>
using namespace std;

// Method 1
// int slowExponentiation(int a, int b){
//     int ans=1;
//     for(int i=0; i<b;i++){
//         ans*=a;
//     }
//     return ans;
// }

// Method 2
    int fastExponentiation(int a, int b){
        int ans = 1;
        while(b>0){
            if(b & 1){
                ans = ans*a;
            }
            a *= a;
            b>>=1;
        }
        return ans;
    }

int main(){
    // cout<<slowExponentiation(5,4)<<endl;
    cout<<fastExponentiation(5,4)<<endl;
    return 0;
}