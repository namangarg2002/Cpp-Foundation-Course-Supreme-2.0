#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(vector<int> &v){
    int n = v.size();

    for(int i=0; i<n-1; i++){
        int minIndex = i;  //ith element is smallest
        for(int j=i+1; j<n; j++){
            // for increasing order
            if(v[j]< v[minIndex]){
                minIndex = j;
            }
            // for decreasing order
            // if(v[j]> v[minIndex]){
            //     minIndex = j;
            // }
        }
        // swap ith index with min index
        swap(v[i], v[minIndex]);
    }
}

int main(){
    vector<int> v = {44,33,55,22,11};

    selectionSort(v);
    print(v);
    return 0;
}