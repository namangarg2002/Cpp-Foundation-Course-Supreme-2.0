#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseKElement(queue<int> &q, int k)
{
  stack<int> st;
  int n = q.size();

  if (k > n || k == 0)
  {
    return;
  }

  // step 1: push first K element from queue to stack
  for (int i = 0; i < k; i++)
  {
    int QueueElement = q.front();
    q.pop();
    st.push(QueueElement);
  }

  // step 2: push element of stack into queue
  while (!st.empty())
  {
    int stackElement = st.top();
    st.pop();
    q.push(stackElement);
  }

  // step 3: push (n-k) element of queue to queue

  for (int i = 0; i < n - k; i++)
  {
    int remainingElement = q.front();
    q.pop();
    q.push(remainingElement);
  }
}

int main()
{
  queue<int> q;

  int k = 3;

  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  reverseKElement(q, k);

  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}