#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string rotatedStringByK(string str, int k)
{
  stack<char> st1, st2;
  int space_count = 0;

  for (int i = 0; i < str.size(); ++i)
  {
    if (space_count < k && str[i] != ' ')
    {
      st1.push(str[i]);
    }
    else
    {
      if (str[i] == ' ')
      {
        st1.push(' ');
        space_count++;
      }
      st2.push(str[i]);
    }
  }
  st2.push(' ');

  // push element of stack1 into a string str1
  string str1 = "";
  while (!st1.empty())
  {
    str1 += st1.top();
    st1.pop();
  }

  // reverse str1
  reverse(str1.begin(), str1.end());

  // push reversedStr1 to Stack2 st2
  for (char ch : str1)
  {
    st2.push(ch);
  }

  // Release memory of str1
  string().swap(str1); // Swap with an empty string to free memory

  // // push element of stack2 into a string str2
  string str2 = "";
  while (!st2.empty())
  {
    str2 += st2.top();
    st2.pop();
  }

  // reverse str2
  reverse(str2.begin(), str2.end());

  // Release memory of st2
  stack<char>().swap(st2); // Swap with an empty stack to free memory

  // remove leading spaces
  str2.erase(0, str2.find_first_not_of(' '));

  return str2;
}

int main()
{
  string str = "abcdef gh ijk lmnop q";
  int k = 3;

  string result = rotatedStringByK(str, k);
  cout << result << endl;
  return 0;
}