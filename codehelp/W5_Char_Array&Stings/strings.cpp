#include<iostream>
using namespace std;

int main(){

    // // Creation
    // string name;

    // // input
    // // cin>>name;
    // getline(cin, name);

    // // print
    // cout<<"Printing Name : "<<name<<endl;

    // // print 1st charracter of string
    // cout<<"Printing first Charracter : "<<name[0]<<endl;

    // // print all character in a string untill we got NULL CHARACTER
    // int index = 0;
    // while(name[index]!='\0'){
    //     cout<<"Index : "<<index<<" character: "<<name[index]<<endl;
    //     index++;
    // }
    // cout<<"At Index 6 : "<<name[4]<<endl;
    // int value = (int)name[7];
    // cout<<"Value : "<<value<<endl;


    // string name;

    // cin>>name;

    // // empty string
    // string temp = "";


    // cout<<"Length of String :  "<<name.length()<<endl;
    // cout<<"Length of String :  "<<name.empty()<<endl;
    // cout<<"Length of String :  "<<temp.empty()<<endl;
    // cout<<"Character At position 0 is: "<<name.at(0);
    // cout<<"Front character of string is: "<<name.front()<<endl;
    // cout<<"Back character of string is: "<<name.back()<<endl;

    // string str1 = "Love ";
    // string str2 = "Babbar";

    // cout<<"Before Appending : "<< endl;
    // cout<<str1<<endl;
    // cout<<str2<<endl;

    // // Append
    // str1.append(str2);

    // cout<<"After Appending : "<< endl;
    // cout<<str1<<endl;
    // cout<<str2<<endl;

    // Erase
    // string desc = "This is a car";
    // desc.erase(4, 3);
    // cout<<desc<<endl;

    // Insert
    // string name = "Love Babbar";
    // string middle = "Kumar ";

    // name.insert(5, middle);
    // cout<<"Printing name: "<<name<<endl;

    // // Push_back
    // string name = "love";

    // cout<<name<<endl;
    // name.push_back('R');
    // cout<<name<<endl;

    // // Pop_back

    // name.pop_back();
    // cout<<name<<endl;

    // // Find
    // string str1 = "yaar tera super star desi kalakaar";
    // string str2 = "star";

    // if(str1.find(str2) == string::npos){
    //     // not found
    //     cout<<"Not Found"<<endl;
    // }else{
    //     cout<<"Found"<<endl;
    // }

    // // Compare
    // string str1 = "babbar";
    // string str2 = "babbar";

    // if(str1.compare(str2)==0){
    //     cout<<"Matching"<<endl;
    // }else{
    //     cout<<"Not Matching "<<endl;
    // }

    // Substring

    string desc = "this is a car, big daddy of all SUVs";
    cout<<desc.substr(19, 5)<<endl;



    return 0;
}