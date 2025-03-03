#include <iostream>
#include <stack>
using namespace std;

void insertSortedStack(stack<int> &st, int element)
{
  // base case
  if (st.empty() || element > st.top())
  {
    st.push(element);
    return;
  }

  // 1 case solve
  int temp = st.top();
  st.pop();

  // recursion
  insertSortedStack(st, element);

  // back tracking
  st.push(temp);
}

int main()
{
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);

  int element = 5;

  insertSortedStack(st, element);

  while ((!st.empty()))
  {
    cout << st.top() << " ";
    st.pop();
  }

  return 0;
}