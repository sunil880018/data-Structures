//Queue using Linked List
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Queue
{
   private:
   Node *rear,*front;
   public:
   Queue()
   {
       rear=NULL;
       front=NULL;
   }
   ~Queue()
   {
       while(!empty())
        pop();
   }
    void push(int data);
    void pop();
    bool empty();
    int Front();
};
void Queue::push(int data)
{
    if(rear==NULL && front==NULL)
     {
         rear=new Node(data);
         front=rear;
     }
     else
     {
         Node *n=new Node(data);
         rear->next = n;
         rear=n;
     }
}
void Queue::pop()
{
    if(front!=NULL && front->next==NULL)
     {
         rear=NULL;front=NULL;
     }
     else if(front!=NULL)
     {
         Node *n=front;
         front=front->next;
     }
}
bool Queue::empty()
{
    if(front==NULL && rear==NULL)
      return true;
    return false;
}
int Queue::Front()
{
    if(front)
     return front->data;
    return -1;
}
int main()
{
  Queue Q;
  Q.push(34);
  while(!Q.empty())
  {
      cout<<Q.Front()<<" ";
      Q.pop();
  }
}