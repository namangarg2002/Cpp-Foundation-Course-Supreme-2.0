#include<iostream>
using namespace std;

int factorial(int n){
    // base case
    if(n==0 || n==1){
        return 1;
    }
    // processing

    // recursive call
    int recursionKaAns = factorial(n-1);
    // processing
    int finalAns = n * recursionKaAns;
    return finalAns;
}

void printingCounting(int n){
    if(n==1){
        cout<<1<<" ";
        return;
    }
    cout<<n<<" ";
    printingCounting(n-1);
}

int pow(int n){
    // base case
    if(n==0){
        return 1;
    }
    int ans = 2 * pow(n-1);
    return ans;
}
int fibonacci(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }
    int ans =  fibonacci(n-1) + fibonacci(n-2);
    return ans;
}
int sum(int n){
    if(n==0){
        return 0;
    }
    return n + sum(n-1);
}
void printArray(int a[], int n){
    if(n==0) return;
    cout<<*a<<" ";
    printArray(a+1, n-1);
}



int main(){
    int num = 5;
    // cout<<factorial(num)<<endl;
    // printingCounting(num);
    // cout<<pow(num);
    // cout<<fibonacci(num);
    // cout<<sum(num);

    int arr[] = {1,2,3,4,5};
    int n = 5;
    printArray(arr, n);
    
    return 0;
}