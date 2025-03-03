#include <iostream>
#include <queue>
using namespace std;

int main()
{
  string str = "ababc";
  queue<char> q;

  int freq[26] = {0};

  for (int i = 0; i < str.length(); i++)
  {
    char ch = str[i];
    freq[ch - 'a']++;
    q.push(ch);

    // answer find out
    while (!q.empty())
    {
      char frontCharacter = q.front();
      if (freq[frontCharacter - 'a'] > 1)
      {
        // means that's not the answer
        q.pop();
      }
      else
      {
        // freq==1 yahi answer hai
        cout << frontCharacter << "->";
        break;
      }
    }
    if (q.empty())
    {
      // koi answer nhi nikla.
      cout << '#' << "->";
    }
  }

  return 0;
}