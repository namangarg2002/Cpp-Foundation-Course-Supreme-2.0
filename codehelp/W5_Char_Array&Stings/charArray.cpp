#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int findLength(char ch[], int size){
    int length = 0;

    // using while loop
    int index = 0;
    while(ch[index]!='\0'){
        index++;
        length++;
    }
    // using for loop
    // for(int i=0; i<size; i++){
    //     if(ch[i]=='\0'){
    //         //stoping condition
    //         break;
    //     }
    //     else{
    //         length++;
    //     }
    // }
    return length;
}

void reverseSting(char ch[], int size){
    int i = 0;
    int j = size-1;

    while(i<=j){
        swap(ch[i], ch[j]);
            i++;
            j--;
    }
}

void convertToUpperCase(char ch[], int size){
    int index = 0;
    while(ch[index]!= '\0'){
        char currentCharacter = ch[index];
        // check if lowervase, then convert to upper case
        if(currentCharacter>='a'&& currentCharacter<='z'){
            ch[index] = currentCharacter - 'a' + 'A';
        }
        index++;
    }

}

void convertToLowerCase(char ch[], int size){
    int index = 0;
    while(ch[index]!= '\0'){
        char currentCharacter = ch[index];
        // check if lowervase, then convert to upper case
        if(currentCharacter>='A'&& currentCharacter<='Z'){
            ch[index] = currentCharacter - 'A' + 'a';
        }
        index++;
    }

}

void replaceAtWithSpace(char ch[], int size){
    int index = 0;
    while(ch[index]!='\0'){
        char curr = ch[index];
        if(curr == '@'){
            ch[index]=' ';
        }
        index++;
    }
}

bool checkPalindrome(char ch[], int size){
    int i = 0;
    int j = size-1;

    while(i<=j){
        if(ch[i]==ch[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    // Char Array Creation
    // char ch[10];
    // // input
    // cin>>ch;

    // // print
    // cout<<"Printing the value of ch: "<<ch;

    // INPUT FOR INT ARRAY
    // int arr[10];
    // for(int i=0; i<10; i++){
    //     cin>>arr[i];
    // }


    // // finding ASCII value of Null Character 
    // char ch[10];

    // cin>> ch;
    // cout<<"Printing the value of ch: "<<ch<<endl;
    // // printing using loop
    // for(int i=0;i<10; i++){
    //     cout<<"At Index: "<<i<<" "<<ch[i]<<endl;
    // }
    // char temp = ch[5];
    // int value = (int)temp;
    // cout<<"Printing integer value: "<<value<<endl;


    // char ch[100];

    // // cin>>ch;
    // cin.getline(ch, 100);

    // cout<<"printing the value of ch: "<<ch<<endl;

    // // length of string 

    // char ch[100];
    // // cin>>ch;
    // cin.getline(ch, 100);
    // int len = findLength(ch, 100);

    // cout<<"Length of string is : "<<len<<endl;
    // cout<<"Printing length: "<<strlen(ch)<<endl; // utility function for finding length of a string

    // // reverse of string 

    // char ch[100];

    // cin.getline(ch, 100);
    // cout<<"Before : "<<ch<<endl;
    // // int len = findLength(ch, 100);
    // // reverseSting(ch, len);
    // reverse(ch, ch + strlen(ch));   // STL function for reversing of a string
    // cout<<"After : "<<ch<<endl;

    // // UPPERCASE

    // char ch[100];

    // cin.getline(ch, 100);
    // cout<<"before : "<<ch<<endl;
    // convertToUpperCase(ch, 100);
    // cout<<"after : "<<ch<<endl;

    // // Replace @ with space 

    // char ch[100];

    // cin.getline(ch,100);
    // cout<<"Before Replacing : "<<ch<<endl;
    // int len = strlen(ch);
    // replaceAtWithSpace(ch, len);
    // cout<<"After Replacing : "<<ch<<endl;

    // Check Palindrome

    char ch[100];

    cin.getline(ch,100);
    int len = strlen(ch);
    convertToLowerCase(ch, len);
    bool isPalindrome = checkPalindrome(ch, len);
    if(isPalindrome){
        cout<<"Valid"<<endl;
    }else{
        cout<<"Invalid!!"<<endl;
    }

    return 0;
}