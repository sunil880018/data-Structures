//Circular List
#include<iostream>
using namespace std;
struct Node 
{
   int data;
   Node *next;
   Node(int x)
   {
       data=x;
       next=NULL;
   }
};

class Circular_List
 {
    private:
      Node *root;
    public:
    Circular_List()
    {
        root=NULL;
    }
    ~Circular_List()
    {
        deleteAtFront();
    }
     void insertAtFront(int data);
     void insertAtLast(int data);
     void insertAtPos(int i,int data);
     void deleteAtFront();
     void deleteLast();
     void deleteAtPos(int i);
     Node* search(int data);
     void display();
};
void Circular_List::insertAtFront(int data)
{
  if(root==NULL)
    {
        root=new Node(data);
        root->next=root;
    }
    else
    {
        Node *n=new Node(data);
        Node *t=root;
        while(t->next!=root)
            t=t->next;
        n->next=root;
        t->next=n;
        root=n;
    }
}
void Circular_List::insertAtLast(int data)
{
    if(root==NULL)
    {
        root=new Node(data);
        root->next=root;
    }
    else
    {
        Node *t=root;
        while(t->next!=root)
            t=t->next;
        Node*n=new Node(data);
        n->next=root;
        t->next=n;
    }
}
void Circular_List::insertAtPos(int i,int data)
{
  if(root!=NULL)
  {
      Node *t=search(i);
      if(t->next==root)
          insertAtLast(data);
      else
      {
          Node*n=new Node(data);
          n->next=t->next;
          t->next=n;
      }
  }
}
void Circular_List::deleteAtFront()
{
     if(root)
     {
         Node *t=root;
         while(t->next!=root)
         {
             t=t->next;
         }
         Node *p=root;
         root=root->next;
         t->next=root;
         delete p;
     }
}

void Circular_List::deleteLast()
{
     if(root)
     {
         if(root->next==root)
            {
                delete root;
                root = NULL;
            }
         else
         {
             Node *t=root;
             while(t->next->next!=root)
                 t=t->next;
             Node *p=t->next;
             t->next=root;
             delete p;
         }
     }
}

void Circular_List::deleteAtPos(int i)
{
     if(root)
     {
         if(root->data == i)
             deleteAtFront();
         else 
         {
             Node *t=root;
             while(t->next->next!=root)
             {
                 if(t->next->data == i && t->next->next!=root)
                 {
                     Node *p=t->next;
                     t->next=t->next->next;
                     delete p;
                     return;
                 }
                 t=t->next;
             }
             if(t->next->data==i && t->next->next == root)
                deleteLast();
         }
     }
}
Node* Circular_List::search(int data)
{
    if(root)
    {
      Node *t=root;
      while(t->next!=root)
      {
          if(t->data == data)
           return t;
          t=t->next;
      }
      if(t->data == data)
        return t;
    }
    return NULL;
}
void Circular_List::display()
{
  if(root)
  {
      Node *t=root;
      while(t->next!=root)
      {
          cout<<t->data<<" ";
          t=t->next;
      }
      cout<<t->data;
  }
}
int main()
{
  Circular_List L;
  L.insertAtFront(45);
  L.insertAtFront(25);
  L.insertAtFront(95);
  L.insertAtFront(55);
  L.insertAtLast(78);
  L.insertAtPos(78,88);
  L.display();
  L.deleteAtPos(88);
  cout<<endl;
  L.display();
  return 0;
}