#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
  stack<int> st;

  // one by one queue se element lo or stack m daal do
  while (!q.empty())
  {
    int frontElement = q.front();
    q.pop();

    st.push(frontElement);
  }

  // one by one stack se lo or queue m push kr do
  while (!st.empty())
  {
    int topElement = st.top();
    st.pop();

    q.push(topElement);
  }
}

int main()
{
  queue<int> q;

  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);

  reverseQueue(q);

  cout << "Printing Queue : " << endl;
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}