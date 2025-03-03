#include<iostream>
using namespace std;

int main(){
    int op;
    float a,b, ans;
    cin >>a>>b;

    cout<<"what operation do you want"<<endl;
    cout<<"Press 0 for Addition, 1 for Subtraction, 2 for Multiplication, 3 for Divivion"<<endl;
    cin>> op;

    switch(op){
        case 0:
        ans = a + b;
        break;
        case 1:
        ans = a - b;
        break;
        case 2:
        ans = a*b;
        break;
        case 3:
        ans = (a/b);
        break;
        default:
        cout<<"Invalid operation"<<endl;
        return 0;
    }
    cout<<"Your answer is  : "<<ans<<endl;
    return 0;
}