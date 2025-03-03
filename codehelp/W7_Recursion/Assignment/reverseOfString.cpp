#include<iostream>
using namespace std;

void reverse(string &str, int s, int e){
    // base Case
    if(s>=e) return;

    // ek Case 
    swap(str[s], str[e]);

    // baki recursion sambhal lega
    reverse(str, s+1, e-1);
}

int main(){
    string str;
    cin>>str;
    int start = 0;
    int end = str.size()-1;
    reverse(str, start, end);
    cout<<str<<endl;
    return 0;
}