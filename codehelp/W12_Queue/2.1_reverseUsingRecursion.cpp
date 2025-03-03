#include <iostream>
#include <queue>
using namespace std;

void reverseUsingRecursion(queue<int> &q)
{
  // base case
  if (q.empty())
  {
    return;
  }

  int element = q.front();
  q.pop();

  reverseUsingRecursion(q);

  q.push(element);
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

  reverseUsingRecursion(q);

  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}