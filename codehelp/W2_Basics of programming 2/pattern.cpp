#include<iostream>
using namespace std;

int main(){
    // Full pyramid pattern

    // int n;
    // cin>>n;
    
    // for(int i=0; i<n; i++){
    //     // space
    //     for(int j=0; j<n-i-1; j++){
    //         cout<<" ";
    //     }
    //     // star
    //     for(int j=0; j<i+1; j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;

    // }

    // Inverted full pyramid

    // int n;
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<=i; j++){
    //         cout<<" ";
    //     }
    //     for(int j=0; j<n-i; j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // fully pyramid(Diamond Pattern)

    // int n;
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n-i-1; j++){
    //         cout<<" ";
    //     }
    //     for(int j=0; j<i+1; j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<i; j++){
    //         cout<<" ";
    //     }
    //     for(int j=0; j<n-i; j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // Hollow Pyramid

    // int n;
    // cin>>n;

    // for (int i=0; i<n; i++){
    //     int k=0;
    //     for(int j=0; j<2*n-1; j++){
    //         if(j<n-i-1){
    //             cout<<" ";
    //         }else if(k<2*i+1){
    //             if(k==0 || k==2*i){
    //                 cout<<"*";
    //             }else{
    //                 cout<<" ";
    //             }
    //             k++;
    //         }else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

// OOOOOOOOOOOOOOOORRRRRRRRRRRRRRRRRRRRRR

    // int n;
    // cin>>n;
    
    // for(int i=0; i<n; i++){
    //     // space
    //     for(int j=0; j<n-i-1; j++){
    //         cout<<" ";
    //     }
    //     // star
    //     for(int j=0; j<i+1; j++){
    //         if(j==0 || j==i){
    //             cout<<"* ";   
    //         }else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;

    // }

    // Inverted hollow pyramid

    // int n;
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<=i; j++){
    //         cout<<" ";
    //     }
    //     for(int j=0; j<n-i; j++){
    //         if(j==0 || j==n-i-1){
    //             cout<<"* ";
    //         }else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // Hollow Diamond 

    // int n;
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     // space
    //     for(int j=0; j<n-i-1; j++){
    //         cout<<" ";
    //     }
    //     for(int j=0; j<i+1; j++){
    //         if(j==0 || j==i)
    //         cout<<"* ";
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }
    // for(int i=0; i<n; i++){
    //     // space
    //     for(int j=0; j<i; j++){
    //         cout<<" ";
    //     }
    //     for(int j=0; j<n-i; j++){
    //         if(j==0 || j==n-i-1)
    //         cout<<"* ";
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // int n;
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n-i; j++){
    //         cout<<"*";
    //     }
    //     for(int j=0; j<2*i+1; j++){
    //         cout<<" ";
    //     }
    //     for(int j=0; j<n-i; j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<i+1; j++){
    //         cout<<"*";
    //     }
    //     for(int j=0; j<2*(n-i)-1; j++){
    //         cout<<" ";
    //     }
    //     for(int j=0; j<i+1; j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    // int n;
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<2*i+1; j++){
    //         if(j%2==0){
    //             cout<<i+1;
    //         }else{
    //             cout<<"*";
    //         }
    //     }
    //     cout<<endl;
    // }
    // for(int i=0; i<n-1; i++){
    //     for(int j=0; j<n-2*i+1; j++){
    //         if(j%2==0){
    //             cout<<n-i-1;
    //         }else{
    //             cout<<"*";
    //         }
    //     }
    //     cout<<endl;
    // }

    // int n;
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n-i; j++){
    //         if(i==0 || i==n-1){
    //             cout<<"* ";
    //         }else{
    //             if(j==0 || j==n-i-1){ 
    //                 cout<<"* ";
    //             }else{
    //                 cout<<"  ";
    //             }
    //         }
    //     }
    //     cout<<endl;
    // }

    // int n;
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n-i; j++){
    //         if(i==0 ){
    //             cout<<j+1<<" ";
    //         }else if (i==n-1){
    //             cout<<n<<" ";
    //         }else {
    //             if (j==0){
    //                 cout<<i+1<<" ";
    //             }else if(j==n-i-1){
    //                 cout<<n<<" ";
    //             }else{
    //                 cout<<"  ";
    //             }
    //         }
    //     }
    //     cout<<endl;
    // }

    // int n;
    // cin>>n;

    // for (int i=0; i<n; i++){
    //     for (int j=0; j<n-i-1; j++){
    //         cout<<" ";
    //     }
    //     for(int j=0; j<i+1; j++){
    //         cout<<j+1;
    //     }
    //     for(int j=i-1;j>=0; j--){
    //         cout<<j+1;
    //     }
    //     cout<<endl;
    // }

    // int n;
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n-i+3; j++){
    //         cout<<"*";
    //     }
    //     for(int j=0; j<i+1; j++){
    //         cout<<i+1<<"*";   
    //     }
    //     for(int j=n-i+2;j>0;j--){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    // int n;
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     for(int j=0 ; j<i+1; j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0; i<n-1; i++){
    //     for(int j=n-i-1; j>0; j--){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    // int n, k=1;
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<i+1; j++){
    //         cout<<k<<" ";
    //         k++;

    //     }
    //     cout<<endl;
    // }


    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<"*";
        }
        for(int j=0; j<2*(n-i-1); j++){
            cout<<" ";
        }
        for(int j=0; j<i+1; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            cout<<"*";
        }
        for(int j=0; j<2*i; j++){
            cout<<" ";
        }
        for(int j=0; j<n-i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    
}