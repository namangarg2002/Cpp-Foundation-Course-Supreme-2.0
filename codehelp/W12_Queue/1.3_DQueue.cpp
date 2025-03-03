#include <iostream>
#include <deque>
using namespace std;

int main()
{
  // creation
  deque<int> dq;

  // pushing element
  dq.push_back(10);
  dq.push_front(20);

  // pop back and pop front
  dq.pop_back();
  dq.pop_front();

  // front and rear element
  cout << dq.front() << endl;
  cout << dq.back() << endl;
  // size
  cout << dq.size() << endl;

  return 0;
}