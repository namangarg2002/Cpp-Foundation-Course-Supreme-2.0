#include<iostream>
#include<vector>
using namespace std;

vector<bool> Sieve(int n){
    // create a sieve array of n size teling isPrime
    vector<bool>sieve(n+1, true);
    sieve[0]=sieve[1]=false;

    for(int i=2; i*i<=n;i++){ // optimization 2 for outer loop
        if(sieve[i]==true){
            // int j=i*2;
            int j=i*i; //optimization 1: first unamrked number would be i*i, as others have been marked by 2 to ( i - 1)
            while(j<n){
                sieve[j]=false;
                j += i;
            }
        }
    }
    return sieve;

}

int main(){
    int n = 50;
    vector<bool>sieve=Sieve(n);
    for(int i=0; i<n; i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}