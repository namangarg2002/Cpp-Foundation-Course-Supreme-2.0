#include<iostream>
using namespace std;

// int main(){
//     int bal;
//     cout<<"Balance : ";
//     cin>>bal;
//     if (bal >= 10){
//         cout<<"Maggie"<<endl;
//     }
//     return 0;
// }

// int main(){
//     int sides;
//     cin>>sides;
//     if (sides == 3){
//         cout<<"Triangle"<<endl;
//     }else {
//         cout<<"Not a Triangle"<<endl;
//     }
//     return 0;
// }

int main(){
    int sides;
    cin>>sides;
    if (sides <= 2){
        cout<<"Not possible to dram any figure"<<endl;
    }else if(sides == 3){
        cout<<"Triangle"<<endl;
    }else if (sides == 4){
        cout<<"Rectangle/Square"<<endl;
    }else if (sides == 5){
        cout<<"Pentagon"<<endl;
    }else{
        cout<<"Mujhe nhi pta"<<endl;
    }
    return 0;
}