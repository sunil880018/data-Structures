//Queue using Array
#include<iostream>
using namespace std;
class Queue
{
    private:
    int capacity;
    int rear,front;
    int *q;
    public:
    Queue()
    {
        capacity=10;
        rear=-1;front=-1;
        q = new int[capacity];
    }
    Queue(int cap)
    {
        capacity=cap;
        rear=-1;front=-1;
        q = new int[capacity];
    }
    ~Queue()
    {
        delete q;
    }
    void push(int data);
    void pop();
    bool empty();
    int Front();
};
void Queue::push(int data)
{
   if(rear==-1 && front == -1)
     {
         rear++;
         q[rear]=data;
         front++;
     }
   else if(rear+1 < capacity && rear+1 !=front)
   {
       rear++;
       q[rear] = data;
   }
   else if(rear == capacity-1)
   {
       if(rear%capacity -1!=front)
       {
           rear=0;
           q[rear] = data;
       }
   }
}
void Queue::pop()
{
   if(rear == front)
     {
         rear=-1;
         front=-1;
     }
   else if(front+1 <capacity && front+1!=rear)
   {
       front++;
   }
   else if(front+1==capacity)
   {
       front=0;
   }
   else 
   front++;
}
bool Queue::empty()
{
    if(front==-1 && rear == -1)
      return true;
    return false;
}
int Queue::Front()
{
    if(front!=-1)
      return q[front];
    return -1;
}
int main()
{
  Queue Q(6);
  Q.push(7);
  Q.push(34);
  Q.push(2);
  Q.push(78);
  Q.push(70);
  Q.pop();
  Q.pop();
  Q.pop();
  Q.pop();
  Q.pop();
  Q.push(55);
  while(!Q.empty())
  {
      cout<<Q.Front()<<" ";
      Q.pop();
  }
}