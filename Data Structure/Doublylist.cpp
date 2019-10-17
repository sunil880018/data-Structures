// Doubly linked List
#include<iostream>
using namespace std;
struct Node
     {
         int data;
         Node *prev,*next;
         Node(int x)
         {
             data = x;
             prev=NULL;
             next = NULL;
         }
     };
class Double_List
{
    private:
     Node *root ;
     public:
     Double_List()
     {
         root=NULL;
     }
     ~Double_List()
     {
         deleteAtFront();
     }
     void insertAtFront(int data);
     void insertAtLast(int data);
     void insertAtPos(int i,int data);
     void deleteAtFront();
     void deleteLast();
     void deleteAtPos(int i);
     int size();
     Node* search(int data);
     bool searchValue(int data);
     void sort();
     int front();
     int back();
     void reverse();
     void display();
};

void Double_List::insertAtFront(int data)
{
  if(root==NULL)
  {
      root=new Node(data);
  }
  else
  {
      Node *n=new Node(data);
      n->next=root;
      root->prev=n;
      root=n;
      
  }
  
}

void Double_List::insertAtLast(int data)
{
  if(root==NULL)
  {
      root=new Node(data);
  }
  else
  {
      Node*t=root;
      while(t->next!=NULL)
       t=t->next;
      Node *n=new Node(data);
      t->next=n;
      n->prev = t;
  }
}

void Double_List::insertAtPos(int i,int data)
{
  if(root==NULL)
  {
      root=new Node(data);
  }
  else
  {
      Node*t=search(i);
      if(t->next==NULL)
        {
            Node *n = new Node(data);
            t->next=n;
            n->prev=t;
        }
        else
        {
            Node *n = new Node(data);
            n->next=t->next;
            t->next=n;
            n->prev=t;
        }
  }
}
void Double_List::deleteAtFront()
{
   if(root!=NULL)
   {
       Node *t=root;
       root=root->next;
       root->prev=NULL;
       delete t;
   }
}
void Double_List::deleteLast()
{
  if(root!=NULL)
   {
       Node *t=root;
       while(t->next!=NULL)
       {
           t=t->next;
       }
       Node *p=t->prev;
       p->next=NULL;
       delete t;
   }
}
void Double_List::deleteAtPos(int i)
{
  if(root!=NULL)
  {
      if(root->data ==i && root->next ==NULL )
      {
          delete root;
          root=NULL;
      }
      else
      {
          Node *t=search(i);
          if(t!=NULL && t->next==NULL)
          {
              Node *p=t->prev;
              p->next=NULL;
              delete t;
          }
          else if(t!=NULL && t->prev ==NULL)
          {
              root=t->next;
              root->prev=NULL;
              delete t;
          }
          else if(t!=NULL)
          {
              t->prev->next=t->next;
              t->next->prev=t->prev;
          }
          
      }
      
  }
}
int Double_List::size()
{
  if(root)
  {
    Node *t=root;
    int count=0;
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
  }
  return 0;
}
Node* Double_List::search(int data)
{
 if(root!=NULL)
 {
   Node *t=root;
   while(t!=NULL)
   {
       if(t->data == data)
         return t;
        t=t->next;
   }
 }
 return NULL;
}
bool Double_List::searchValue(int data)
{
   Node *t=search(data);
   if(t)
     return true;
    return false;
}
int Double_List::front()
{
  if(root)
    return root->data;
  return -1;
}
int Double_List::back()
{
    if(root==NULL)
      return -1;
    else
    {
        Node*t=root;
        while(t->next!=NULL)
          t=t->next;
        return t->data;
    }
}
void Double_List::reverse()
{
  if(root)
  {
      if(root->next!=NULL)
      {
          Node *t=root->next;
          t->prev=NULL;
          root->next=NULL;
          while(t->next!=NULL)
          {
            root->prev=t;
            Node *p=t->next;
            t->next=root;
            root=t;
            t=p;
          }
          root->prev=t;
          t->next=root;
          root=t;
          root->prev=NULL;
      }
  }
}
void Double_List::display()
{
    if(root)
    {
        Node *t=root;
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
    }
}
int main()
{
  Double_List D;
  D.insertAtLast(10);
  D.insertAtLast(30);
  D.insertAtLast(20);
  D.insertAtLast(70);
  D.insertAtLast(80);
  D.display();
  cout<<endl;
  D.reverse();
  D.display();
}