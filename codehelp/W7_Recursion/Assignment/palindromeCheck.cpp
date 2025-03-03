#include<iostream>
using namespace std;

bool isPalindrome(string &str , int s, int e){
    // base case
    if(s>=e) return true;

    // ek case solution
    if(str[s]!=str[e]){
        return false;
    }
     return isPalindrome(str, s+1, e-1);

}

int main(){
    string str;
    cin>>str;
    cout<<isPalindrome(str, 0, str.size()-1)<<endl;
    return 0;
}