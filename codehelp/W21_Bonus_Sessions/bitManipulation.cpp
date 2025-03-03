#include <iostream>
#include <vector>
using namespace std;
void checkEvenOdd(int n)
{
  if (n & 1)
  {
    cout << "Odd" << endl;
  }
  else
  {
    cout << "Even" << endl;
  }
}
void getIthBit(int &n, int i)
{
  int mask = (1 << i);
  if (n & mask)
  {
    cout << "bit -> 1" << endl;
  }
  else
  {
    cout << "bit -> 0" << endl;
  }
}
void setIthBit(int &n, int i)
{
  int mask = (1 << i);
  n = n | mask;
  // cout << "Updated Number is : " << n << endl;
}
void clearIthBitUsingXor(int &n, int i)
{
  int mask = (1 << i);
  n = n ^ mask;
  // cout << "Updated Number is : " << n << endl;
}
void clearIthBitUsingAnd(int n, int i)
{
  int mask = (1 << i);
  mask = ~mask;

  n = n & mask;
  cout << "Updated Number is : " << n << endl;
}
void updateIthBit(int n, int i, int target)
{
  clearIthBitUsingXor(n, i);
  int mask = (target << i);
  n = n | mask;
  cout << "Updated Number is : " << n << endl;
}
void clearLastRangeBits(int n, int i)
{
  int mask = (-1 << i);
  n = n & mask;
  cout << "Updated Number is : " << n << endl;
}
bool checkPowerOf2(int n)
{
  // count set Bit
  int count = 0;
  while (n != 0)
  {
    int lastBit = n & 1;
    if (lastBit)
    {
      count++;
    }
    n = n >> 1;
  }
  if (count == 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool checkPowerOf2UsingFormula(int n)
{
  if ((n & n - 1) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
int SetBitCountUsingFormula(int n)
{
  int count = 0;
  while (n != 0)
  {
    n = (n & (n - 1));
    count++;
  }
  return count;
}
int fastExponentiation(int base, int exp)
{
  if (exp == 0)
  {
    return 1;
  }
  int half = fastExponentiation(base, exp >> 1);

  if (exp & 1)
  {
    return base * half * half;
  }
  else
  {
    return half * half;
  }
}
void clearFromRangeBits(int n, int i, int j)
{
  int a = (-1 << i);
  int b = ~(-1 << j - 1);

  int mask = a | b;
  n = n & mask;
  cout << "Updated Number is : " << n << endl;
}
void getSubsequences(string str)
{
  int n = str.length();
  vector<string> ans;
  for (int num = 0; num < (1 << n); num++)
  {
    // number is ready
    // use karo num to create string

    // num -> set bit -> index -> char -> include
    string temp = "";
    for (int i = 0; i < n; i++)
    {
      // i -> represent index
      char ch = str[i];
      // agar i index pr num k ander set bit present hai
      // toh caracter ko include kar lo
      if (num & (1 << i))
      {
        temp.push_back(ch);
      }
    }
    ans.push_back(temp);
  }
  cout << "Printing the SubSequences" << endl;
  for (auto i : ans)
  {
    cout << i << " ";
  }
}
int main()
{
  // int n = 19;
  // checkEvenOdd(n);

  // int n = 10;
  // int i = 20;
  // getIthBit(n, i);

  // int n = 10;
  // int i = 2;
  // setIthBit(n, i);

  // int n = 10;
  // int i = 1;
  // // clearIthBitUsingXor(n, i);
  // clearIthBitUsingAnd(n, i);

  // int n = 10;
  // int i = 3;
  // int target = 0;
  // updateIthBit(n, i, target);

  // int n = 255;
  // int i = 4;
  // clearLastRangeBits(n, i);

  // int n = 255;
  // // cout << checkPowerOf2(n) << endl;
  // cout << checkPowerOf2UsingFormula(n) << endl;

  // int n = 3;
  // int ans = SetBitCountUsingFormula(n);
  // cout << ans << endl;

  // int base = 2, exp = 7;
  // int ans = fastExponentiation(base, exp);
  // cout << ans << endl;

  // int n = 1023;
  // int i = 9;
  // int j = 2;
  // clearFromRangeBits(n, i, j);

  string str = "abc";
  getSubsequences(str);
  return 0;
}