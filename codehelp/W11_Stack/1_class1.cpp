#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
  int *arr;
  int size;
  int top;

  Stack(int size)
  {
    arr = new int[size];
    this->size = size;
    this->top = -1;
  }

  void push(int data)
  {
    if (top == size - 1)
    {
      cout << "Stack overflow" << endl;
      return;
    }
    top++;
    arr[top] = data;
  }

  void pop()
  {
    if (top == -1)
    {
      cout << "Stack underflow" << endl;
      return;
    }
    top--;
  }

  bool isEmpty()
  {
    if (top == -1)
      return true;
    return false;
  }

  int getTop()
  {
    if (top == -1)
    {
      cout << "Stack is Empty!!!" << endl;
      return -1;
    }
    return arr[top];
  }

  int getSize()
  {
    return top + 1;
  }

  void print()
  {
    cout << "Top: " << top << endl;
    cout << "Top Element: " << getTop() << endl;
    cout << "Stack: ";
    for (int i = 0; i < getSize(); i++)
    {
      cout << arr[i] << " ";
    }
    cout << "\n"
         << endl;
  }
};

int main()
{
  // // creation
  // stack<int> st;

  // // insertion
  // st.push(10);
  // st.push(20);
  // st.push(30);

  // // size Check
  // cout << "Size of stack is: " << st.size() << endl;

  // // remove
  // st.pop();

  // // check empty
  // if (st.empty())
  // {
  //   cout << "Stack is empty" << endl;
  // }
  // else
  // {
  //   cout << "Stack is not empty" << endl;
  // }

  // // Top element
  // cout << "Top element is: " << st.top();

  // Stack st(8);

  // // push
  // st.push(10);
  // st.print();

  // st.push(20);
  // st.print();

  // st.push(30);
  // st.print();

  // st.push(10);
  // st.print();

  // st.push(20);
  // st.print();

  // st.push(30);
  // st.print();

  // st.push(10);
  // st.print();

  // st.push(20);
  // st.print();

  // st.push(30);
  // st.print();

  // st.pop();
  // st.print();
  // st.pop();
  // st.print();
  // st.pop();
  // st.print();

  // cout << "Top Element: " << st.getTop() << endl
  //      << endl;
  // cout << "Size of Stack is : " << st.getSize() << endl
  //      << endl;

  // st.pop();
  // st.pop();
  // if (st.isEmpty())
  // {
  //   cout << "Empty" << endl;
  // }
  // else
  // {
  //   cout << "Not Empty" << endl;
  // }
  // cout << endl;

  return 0;
}