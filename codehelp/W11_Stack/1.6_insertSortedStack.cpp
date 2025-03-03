#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int element)
{
  if (st.empty() || element > st.top())
  {
    st.push(element);
    return;
  }

  // 1 case solve
  int temp = st.top();
  st.pop();

  // recursion
  insertSorted(st, element);

  // back tracking
  st.push(temp);
}

void sortedStack(stack<int> &st)
{
  // base case
  if (st.empty())
    return;

  // 1 case solve
  int temp = st.top();
  st.pop();

  // recursion
  sortedStack(st);

  // backtracking
  insertSorted(st, temp);
}

int main()
{

  stack<int> st;
  st.push(10);
  st.push(5);
  st.push(12);
  st.push(8);
  st.push(9);

  sortedStack(st);

  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }

  return 0;
}