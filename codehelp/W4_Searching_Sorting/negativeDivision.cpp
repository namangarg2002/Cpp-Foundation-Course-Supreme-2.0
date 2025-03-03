#include<iostream>
using namespace std;

int getQuotient(int d, int D){
    int s = 0;
    int e = D;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        if(mid*d == D){
            return mid;
        }else if(mid*d < D){
            // answer storing
            ans = mid;
            // right shift
            s = mid + 1;
        }else{
            // left shift
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    int divisor = 7;
    int dividend = -29;

    int ans = getQuotient(abs(divisor), abs(dividend));

    if((divisor>0 && dividend<0) || (divisor<0 && dividend>0)){
        cout<<-1*ans<<endl;
    }else if(dividend==0 && divisor>0){
        cout<<0<<endl;
    }else if(dividend>0 && divisor==0){
        cout<<"Undefined"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}