#include<iostream>
using namespace std;

// void printLine(){
//     for(int i=0; i<10; i++){
//         cout<<"Sundar ko sundari psnd hai"<<endl;
//     }
// }

// int main(){
//     // printLine();
//     return 0;
// }

// void sumThreeNum(int a,int b,int c){
//     int ans = a + b + c;
//     cout<<"Sum is : "<<ans<<endl;
// }


// int main(){
//     sumThreeNum(1, 2, 3);
//     return 0;
// }

// int SumThreeNum(int a,int b,int c){
//     int sum= a + b + c;
//     return sum;
// }

// int main(){
//     int ans = SumThreeNum(1,2,3);
//     cout<<ans<<endl;

//     return 0; 
// }

// Max Number

// void maxNumber(int a, int b, int c){
//     if(a>b && a>c){
//         cout<<"a is greater"<<endl;
//     }else if( b>a && b>c){
//         cout<<"b is greater"<<endl;
//     }else{
//         cout<<"c is greater"<<endl;
//     }
//     return;
// }
// int main(){
//     maxNumber(1,2,3);
//     return 0;
// }

// 1 to n counting 

// void count(int n){
//     for(int i=0; i<n; i++){
//         cout<<i+1<<endl;
//     }
//     return;
// }

// int main(){
//     count(10);
//     return 0;
// }

// is prime or not

// bool isPrime(int n){
//     if (n <= 1){
//         return false;
//     }
//     for(int i=2; i<n; i++){
//         if (n % i ==0 ){
//             return false;
//         }
//     }
//     return true;
// }
// int main(){
//     bool ans = isPrime(137);
//     cout<<ans<<endl;
//     return 0;
// }

// even or odd

// void evenOdd(int n){
//     if(n%2==0){
//         cout<<"Even"<<endl;
//     }else{
//         cout<<"Odd"<<endl;
//     }
//     return;
// }

// int main(){
//     evenOdd(10);
//     return 0;
// }

// Sum of 1 to N

// int sumN(int n){
//     int sum1=0;
//     for(int i=1; i<=n; i++){
//         sum1=sum1+i;
//     }
//     cout<<sum1<<endl;
//     return 0;
// }
// int main(){
//     sumN(4);
//     return 0;
// }

// Sum of all Even upto 1 to N

// int sumN(int n){
//     int sum=0;
//     for(int i=1; i<=n; i++){
//         if(i%2==0){
//             sum=sum+i;
//         }
//     }
//     cout<<"Sum of even is : "<<sum<<endl;
//     return 0;
// }

// int main(){
//     sumN(7);

//     return 0;
// }


// ****** Home Work *********

// function to find area of circle

// float areaCircle(int r){
//     float pi = 3.14;
//     float area = pi*r*r;
//     cout<<"Area of Circle : "<<area<<endl;
//     return 0;
// }
// int main(){
//     areaCircle(10);
//     return 0;
// }

// function to find factorial of a no.

// int factorail(int n){
//     int fact = 1;
//     for(int i=n; i>0; i--){
//         fact=fact*i;
//     }
//     cout<<"Factorial is: "<<fact<<endl;
//     return 0;
// }
// int main(){
//     factorail(6);
//     return 0;
// }

// function to find factorial of a no.(recurcive case)

// int factorial(int n){
//     if (n==0 || n==1){
//         return 1;
//     }else{
//         return n*factorial(n-1);
//     }
    
// }
// int main(){
//     int n;
//     cin>>n;
//     int fact = factorial(n);
//     cout<<"Factorial of "<<n<<" is : "<<fact<<endl;
// }

// function to find prime from 1 to N

// bool isPrime(int n){
//     if (n==0 || n==1){
//         return false;
//     }
//     for(int i=2; i<n; i++){
//         if (n%i==0){
//             return false;
//         }
//     }
//     return true;
// }

// int main(){
//     int N;
//     cin>>N;
//     for(int i=0; i<=N; i++){
//         if (isPrime(i)){
//             cout<<i<<endl;
//         }
//     }
//     return 0;
// }

// Km to miles

// float kmMiles(int n){
//     float miles;
//     miles = n/1.609344;
//     return miles;
// }
// int main(){
//     float mile = kmMiles(10);
//     cout<<"Miles : "<<mile;
//     return 0;
// }

// Celcius to fahrenheit

// float celToFeh(int n){
//     float ans = ((n*(1.8))+32);
//     return ans;

// }

// int main(){
//     float feh = celToFeh(32);
//     cout<<feh;
//     return 0;
// }

// function to find even or odd (simple method)

// bool checkEven(int n){
//     if(n % 2 == 0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     bool isEven = checkEven(n);
//     if(isEven){
//         cout<<n<<" is Even number"<<endl;
//     }else{
//         cout<<n<<" is Odd number"<<endl;
//     }
// }


// function to find even or odd (Bitwise method)

// bool checkEven(int n){
//     if((n&1) == 0){
//         return true;
//     }else{
//         return false;
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     bool isEven =  checkEven(n);
//     if(isEven){
//         cout<<n<<" is Even Number"<<endl;
//     }else{
//         cout<<n<<" is Odd Number"<<endl;
//     }
// }

// Reverse an integer

// int reverse(int n){
//     int rem = 0;
//     int ans = 0;
//     while(n>0){
//         int digit = n % 10;
//         ans = ans * 10 + digit;
//         n = n / 10;
//     }
//     return ans;

// }
// int main(){
//     int n;
//     cin>>n;
//     int rev = reverse(n);
//     cout<<rev<<endl;
// }

// Set the Kth Bit

// int setKthBit(int n, int k){
//     int mask = 1<<k;
//     int ans = n | mask;
//     return ans;
// }
// int main(){
//     int n, k;
//     cin>>n>>k;
//     int set = setKthBit(n,k);
//     cout<<set<<endl;

// }

// Count All Set Bits

// int countAllSetBit(int n){
//     int count = 0;
//     while(n>0){
//         int bit = n % 2;
//         if(bit == 1){
//             count++;
//         }
//         n = n / 2;
//     }
//     return count;
// }
// int main(){
//     int n;
//     cin>>n;
//     int ans = countAllSetBit(n);
//     cout<<ans<<endl;
// }

// count all Set bits using bitwise operator

// int countAllSetBit(int n){
//     int count = 0;
//     while(n>0){
//         int a = n & 1;
//         if(a==1){
//             count++;
//         }
//         n = n>>1;
//     }
//     return count;

// }
// int main(){
//     int n;
//     cin>>n;
//     int ans = countAllSetBit(n);
//     cout<<ans<<endl;
// }

// create a number using digits

// int createNumUsingDigit(int n){
//     int num = 0;
//     for(int i=0; i<n; i++){
//         cout<<"Enter digit : ";
//         int digit;
//         cin>>digit;
//         num = num * 10 + digit;
//     }
//     return num;
// }
// int main(){
//     int numberOfDigit;
//     cin>>numberOfDigit;
//     int num = createNumUsingDigit(numberOfDigit);
//     cout<<"Digit is : "<<num<<endl;
// }

// integer to Binary

// int intToBinary(int n){
//     int k;
//     for(int i=31; i>=0; i--){
//         k = n >> i;
//         if(k & 1){
//             cout<<"1";
//         }else{
//             cout<<"0";
//         }
//     }
//     return k;
// }
// int main(){
//     int n;
//     cin>>n;
//     intToBinary(n);
// }

// Print all digits of an Ineger

// int PrintAllDigits(int n){
//     int num;
//     while(n){
//         num = n % 10;
//         cout<<num<<endl;
//         n=n/10;
//     }
//     return num;
// }
// int main(){
//     int n;
//     cin>>n;
//     PrintAllDigits(n);
// }

