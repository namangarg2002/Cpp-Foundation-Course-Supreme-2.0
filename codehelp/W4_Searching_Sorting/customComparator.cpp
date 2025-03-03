#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
// bool myComp(int&a, int&b){
//     // return a<b;  //increasing order sorting
//     return a>b;  //decreasing order sorting
// }

void printvv(vector<vector<int>> &v){
    for(int i=0; i<v.size(); i++){
        vector<int>&temp = v[i];
        int a = temp[0];
        int b = temp[1];
        cout<<"("<<a<<","<<b<<")"<<endl;
    }
    cout<<endl;
}
bool mycompfor1Index(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}



int main(){
    // vector<int> v = {44,55,22,11,33};
    // // sort(v.begin(), v.end());  //Increasing order Sorting
    // sort(v.begin(), v.end(), myComp);  //decreasing order Sorting
    // print(v);

    // Vector of vector sorting
    vector<vector<int>>v;
    int n;
    cout<<"Enter Size:\n";
    cin>>n;
    for(int i=0; i<n; i++){
        int a,b;
        cout<<"Enter a,b"<<endl;
        cin>>a>>b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }
    cout<<"Here are the values"<<endl;
    printvv(v);
    cout<<"Soted by 0st Index"<<endl;
    sort(v.begin(), v.end());
    printvv(v);
    cout<<"Soted by 1st Index"<<endl;
    sort(v.begin(), v.end(), mycompfor1Index);
    printvv(v);
    return 0;
}