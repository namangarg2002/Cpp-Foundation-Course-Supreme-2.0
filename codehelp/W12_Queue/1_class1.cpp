#include <iostream>
#include <queue>
using namespace std;

int main()
{
  // creation
  queue<int> q;

  // insertion
  q.push(5);

  // size
  cout << "Size of Queue: " << q.size() << endl;

  // empty
  if (q.empty() == true)
  {
    cout << "Queue is empty" << endl;
  }
  else
  {
    cout << "Queue is not empty" << endl;
  }

  // remove
  q.pop();
  cout << "Size of Queue: " << q.size() << endl;

  if (q.empty() == true)
  {
    cout << "Queue is empty" << endl;
  }
  else
  {
    cout << "Queue is not empty" << endl;
  }

  q.push(10);
  q.push(20);
  q.push(30);

  // front element oof queue
  cout << "Front element of Queue is: " << q.front() << endl;

  // last element of Queue
  cout << "Last Element of Queue is: " << q.back() << endl;

  return 0;
}