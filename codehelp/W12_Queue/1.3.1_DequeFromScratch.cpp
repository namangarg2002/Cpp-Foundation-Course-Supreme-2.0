#include <iostream>
using namespace std;

class Deque
{
public:
  int *arr;
  int size;
  int front;
  int rear;

  Deque(int size)
  {
    arr = new int[size];
    this->size = size;
    front = -1;
    rear = -1;
  }

  void pushBack(int val)
  {

    // OverFlow Case
    if (front == 0 && rear == size - 1 || rear == front - 1)
    {
      cout << "OverFlow: " << endl;
    }
    // empty case
    else if (front == -1 && rear == -1)
    {
      rear++;
      front++;
      arr[rear] = val;
    }
    // Circular Queue Case
    else if (rear == size - 1 && front != 0)
    {
      rear = 0;
      arr[rear] = val;
    }
    else
    {
      // normal Case
      rear++;
      arr[rear] = val;
    }
  }

  void pushFront(int val)
  {
    if (front == 0 && rear == size - 1 || rear == front - 1)
    {
      // overFlow Case
      cout << "OverFlow " << endl;
    }
    else if (front == -1 && rear == -1)
    {
      // empty Case
      front++;
      rear++;
      arr[front] = val;
    }
    else if (front == 0 && rear != size - 1)
    {
      front = size - 1;
      arr[front] = val;
    }
    else
    {
      // normal Case
      front--;
      arr[front] = val;
    }
  }

  void popFront()
  {
    // empty case
    if (front == -1 && rear == -1)
    {
      cout << "UnderFlow" << endl;
    }
    // single element
    else if (front == rear)
    {
      arr[front] = -1;
      rear = -1;
      front = -1;
    }
    // CircularQueue Case
    else if (front == size - 1)
    {
      arr[front] = -1;
      front = 0;
    }
    else
    {
      // normal case
      arr[front] = -1;
      front++;
    }
  }

  void popBack()
  {
    // underFlow
    if (front == -1 && rear == -1)
    {
      cout << "Underflow" << endl;
    }
    else if (front == rear)
    {
      // single element
      arr[rear] = -1;
      front = -1;
      rear = -1;
    }
    else if (rear == 0)
    {
      arr[rear] = -1;
      rear = size - 1;
    }
    else
    {
      // normal case
      arr[rear] = -1;
      rear--;
    }
  }
};

int main()
{

  return 0;
}