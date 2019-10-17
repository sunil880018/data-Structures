// singly linked List
#include<iostream>
using namespace std;
    struct Node
     {
         int data;
         Node *next;
         Node(int x) // Constructor
         {
             data = x;
             next = NULL;
         }
     };
class Single_List 
{
    private:
     Node *root;
     public:
     Single_List()//Constructor
     {
         root =NULL;
     }
     ~Single_List() // Destructor
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
     void display();
};
void Single_List::insertAtFront(int data)
{
   if(root == NULL)
          root = new Node(data);
   else
   {
       Node *n =new Node(data);
       n->next = root;
       root = n;
   }
}

void Single_List::insertAtLast(int data)
{
   if(root == NULL)
          root = new Node(data);
   else
   {
       Node *t=root;
       while(t->next !=NULL)
          t=t->next;
       Node *n =new Node(data);
       t->next =  n;
   }
}

void Single_List::insertAtPos(int i,int data)
{
    if(root == NULL)
      root =new Node(data);
    else
    {
        Node *t =search(i);
        if(t==NULL)
         ;
        else if(t->next!=NULL)
         {
             Node *n = new Node(data);
             n->next = t->next;
             t->next = n;
         }
         else
         {
             t->next = new Node(data);
         }
         
    }
}

void Single_List::deleteAtFront()
{
    if(root!=NULL)
    {
        if (root->next==NULL)
        {
            delete root;
            root=NULL;
        }
        else
        {
            Node *t=root;
            root = t->next;
            delete t;
        }
    }
}

void Single_List::deleteLast()
{
    if(root!=NULL)
    {
        if (root->next==NULL)
        {
            delete root;
            root=NULL;
        }
        else
        {
            Node *t=root;
            while(t->next->next!=NULL)
              t=t->next;
            Node *n=t->next;
            t->next=NULL;
            delete n;
        }
    }
}
void Single_List::deleteAtPos(int i)
{
  if(root!=NULL)
    {
        if(root->next==NULL && root->data == i)
          {
              delete root;
              root=NULL;
          }
         else if(root->next!=NULL && root->data == i)
         {
             Node *n=root;
             root=root->next;
             delete n;
         }
         else
         {
             Node *t=root;
             while(t->next->next!=NULL)
             {
                 if(t->next->data == i)
                 {
                     Node *n=t->next;
                     t->next = t->next->next;
                     delete n;
                     return;
                 }
                t=t->next;
             } 
             if(t->next->data == i)
             {
                 Node *n=t->next;
                 t->next=NULL;
                 delete n;
             }
         }
         
    }
}
int Single_List::size()
{
    if(root!=NULL)
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

Node* Single_List::search(int data)
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

bool Single_List::searchValue(int data)
{
   if(root!=NULL)
   {
      Node *t=root;
      while(t!=NULL)
      {
          if(t->data == data)
             return true;
            t=t->next;
      }
   }
   return false;
}
void Single_List::display()
{
    if(root!=NULL)
    {
        Node*t=root;
        while(t!=NULL)
         {
             cout<<t->data<<" ";
             t=t->next;
         }
    }
}

int main()
{
    Single_List L;
    L.insertAtLast(20);
    L.insertAtLast(60);
    L.insertAtLast(80);
    L.insertAtLast(40);
    L.insertAtLast(10);
    L.insertAtLast(5);
    L.insertAtLast(7);
    L.sort();
    L.display();
}