// Stack Using Linked list
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
class Stack
{
    private:
    Node *root;
    public:
    Stack()
    {
        root=NULL;
    }
    ~Stack()
    {
        while(!empty())
          pop();
    }
    void push(int data);
    void pop();
    int top();
    bool empty();
    int size();
};
void Stack::push(int data)
{
    if(root==NULL)
      root = new Node(data);
    else
    {
        Node *n = new Node(data);
        n->next=root;
        root=n;
    }
}
int Stack::top()
{
    if(root)
     return root->data;
    return -1;
}
void Stack::pop()
{
    if(root)
    {
        Node *n=root;
        root=root->next;
        delete n;
    }
}
bool Stack::empty()
{ 
   if(root)
     return false;
    return true;
}
int Stack::size()
{
    int count=0;
    Stack S;
    while(!empty())
    {
        S.push(top());
        pop();
        count++;
    }
    while(!S.empty())
    {
        push(S.top());
        S.pop();
    }
    return count;
}
int main()
{
  Stack S;
  S.push(23);
  S.push(67);
  S.push(34);
  S.push(25);
  S.push(212);
  S.push(278);
  S.push(78);
  cout<<S.size()<<endl;
    while(!S.empty())
    {
        cout<<S.top()<<" ";
        S.pop();
    }
    
}