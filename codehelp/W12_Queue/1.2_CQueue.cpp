#include <iostream>
using namespace std;

class CQueue
{
public:
  int *arr;
  int size;
  int front;
  int rear;

  CQueue(int size)
  {
    arr = new int[size];
    this->size = size;
    front = -1;
    rear = -1;
  }

  void push(int val)
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

  void pop()
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

  void print()
  {
    cout << "Front: " << front << " Rear: " << rear << endl;
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
  CQueue cq(5);
  cq.print();

  cq.push(10);
  cq.print();

  cq.push(20);
  cq.print();

  cq.push(30);
  cq.print();

  cq.push(40);
  cq.print();

  cq.push(50);
  cq.print();

  cq.push(60);

  cq.pop();
  cq.pop();
  cq.pop();

  cq.print();

  cq.push(100);
  cq.print();

  cq.push(110);
  cq.print();

  cq.push(120);
  cq.print();

  cq.push(130);
  cq.print();

  return 0;
}