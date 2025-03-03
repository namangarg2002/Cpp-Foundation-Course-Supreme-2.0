#include <iostream>
using namespace std;

class Queue
{
public:
  int *arr;
  int size;
  int front;
  int rear;

  Queue(int size)
  {
    arr = new int[size];
    this->size = size;
    front = -1;
    rear = -1;
  }

  void push(int val)
  {
    // check full
    if (rear == size - 1)
    {
      cout << "Queue OverFlow" << endl;
      return;
    }
    else
    {
      // not Full
      if (front == -1 && rear == -1)
      {
        // --> empty case
        front++;
        rear++;
        arr[rear] = val;
      }
      else
      {
        // --> normal case
        rear++;
        arr[rear] = val;
      }
    }
  }

  void pop()
  {
    // check empty
    if (front == -1 && rear == -1)
    {
      cout << "Queue is UndrFlow: " << endl;
      return;
    }
    else
    {
      // --> single element
      if (front == rear)
      {
        arr[front] = -1; // for remembering, if front's Index element is -1 then no element is present at that position.
        front = -1;
        rear = -1;
      }
      else
      {
        // --> normal Case
        arr[front] = -1;
        front++;
      }
    }
  }

  bool isEmpty()
  {
    if (front == -1 && rear == -1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  int getSize()
  {
    if (front == -1 && rear == -1)
    {
      return 0;
    }
    return rear - front + 1;
  }

  int getFront()
  {
    if (front == -1)
    {
      cout << "No element in queue, cannot give front element" << endl;
      return -1;
    }
    else
    {
      return arr[front];
    }
  }

  int getRear()
  {
    if (rear == size)
    {
      cout << "Queue is Full" << endl;
      return -1;
    }
    else
    {
      return arr[rear];
    }
  }

  bool isFull()
  {
    if (size == getSize())
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void print()
  {
    cout << "Printing Queue: ";
    for (int i = 0; i < size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  Queue q(5);
  q.print();

  q.push(10);
  q.print();

  q.push(20);
  q.print();

  q.push(30);
  q.print();

  q.push(40);
  q.print();

  q.push(50);
  q.print();

  cout << "Size of Queue: " << q.getSize() << endl;
  // cout << q.isFull() << endl;

  q.pop();
  q.print();

  cout << "Size of Queue: " << q.getSize() << endl;
  cout << "Queue is empty or not: " << q.isEmpty() << endl;

  q.push(100);
  q.print();
  q.pop();
  q.pop();
  q.pop();
  q.print();

  cout << q.getFront() << endl;
  cout << q.getRear() << endl;

  q.pop();
  q.print();

  cout << q.getSize() << endl;

  return 0;
}