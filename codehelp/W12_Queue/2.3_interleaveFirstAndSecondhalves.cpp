#include <iostream>
#include <queue>
using namespace std;

void interLeave(queue<int> &first)
{
  queue<int> second;
  int n = first.size();

  // STEP1: Put First halve of First Queue into Second Queue
  int mid = n / 2;
  for (int i = 0; i < mid; i++)
  {
    second.push(first.front());
    first.pop();
  }

  // Step2: Merge Both the halves into the original queue
  for (int i = 0; i < mid; i++)
  {
    int temp = second.front();
    second.pop();
    first.push(temp);

    temp = first.front();
    first.pop();
    first.push(temp);
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
  q.push(70);
  // q.push(80);

  interLeave(q);

  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}