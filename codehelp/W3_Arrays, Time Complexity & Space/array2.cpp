#include<iostream>
using namespace std;

int getUniqueElement(int arr[], int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans^arr[i];
    }
    return ans;
}

void allPairs(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"("<<arr[j]<<","<<arr[i]<<") ";
        }
        cout<<endl;

    }
}
void allPairsTriplets(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cout<<"("<<arr[k]<<","<<arr[j]<<","<<arr[i]<<") ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

void sort0And1(int arr[], int n){
    int zeroCount = 0;
    int oneCount = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==0)
            zeroCount++;
        if(arr[i]==1)
            oneCount++;
    }
    // int i;
    // for(i=0 ;i<zeroCount;i++){
    //     arr[i]=0;
    // }

    // for(int j=i ;j<n;j++){
    //     arr[j]=1;
    // }  

                // OR
    
    // int index  = 0;
    // while(zeroCount--){
    //     arr[index] = 0;
    //     index++;
    // }
    // while(oneCount--){
    //     arr[index] = 1;
    //     index++;
    // }

}

void rightShiftBy1(int arr[], int n){
    int temp = arr[n-1];
    for(int i=n-1; i>=1; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

void leftShiftBy1(int arr[], int n){
    int temp = arr[0];
    for(int i=0; i<n; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

int main(){

    // int arr[] = {2,10,11,13,10,2,15,13,15};
    // int n = 9;

    // int finalAns = getUniqueElement(arr, n);
    // cout<<"Final answer is : "<<finalAns<<endl;

    // ALL Pairs

    // int arr[] = {10,20,30};
    // int n = 3;
    // allPairs(arr,n);

    // All Pair Triplet

    // int arr[] = {10,20,30};
    // int n = 3;
    // allPairsTriplets(arr,n);

    // Sort 0 and 1

    // int arr[] = {0,1,0,1,1,0,0,0,0};
    // int n = 9;
    // sort0And1(arr, n);
    // for (int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }

    // right shift of indexes

    // int arr[] = {10,20,30,40,50,60};
    // int n = 6;
    // rightShiftBy1(arr, n);
    // for (int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }

    // left shift of indexes

    int arr[] = {10,20,30,40,50,60};
    int n = 6;
    leftShiftBy1(arr, n);
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    
    return 0;
}