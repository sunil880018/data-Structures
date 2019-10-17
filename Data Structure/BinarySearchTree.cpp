#include<bits/stdc++.h>
using namespace std;
class BinarySearchTree
{
 private:
 struct Node{
     int data;
     Node *lchild;
     Node *rchild;
 };
 Node *root;
 public:
 BinarySearchTree()
 {
     root=NULL;
 }
 void insert(int value)
 {
     if(root==NULL)
       {
           Node *n = new Node();
           n->lchild=NULL;
           n->rchild=NULL;
           n->data = value;
           root=n;
       }
       else
       {
           Node *p,*t=root;
           while (t!=NULL)
           {
               if(value>t->data)
                 {
                         p=t;
                         t=t->rchild;
                 }
               else
                {
                       p=t;
                       t=t->lchild;
                }
           }
           Node *n = new Node();
           n->lchild=NULL;
           n->rchild=NULL;
           n->data = value;
           if(p->data>value)
              p->lchild=n;
           else
            p->rchild=n;
       }
 }
 void LevelOrder()
 {
     if(root==NULL)
      cout<<"empty";
    else
    {
      queue<Node*> q;
      Node *t;
      q.push(root);
      while(!q.empty())
      {
          t=q.front();
          q.pop();
          cout<<t->data<<" ";
          if(t->lchild!=NULL)
             q.push(t->lchild);
          if(t->rchild!=NULL)
             q.push(t->rchild);
      }
    }
 }
 Node* minElement()
 {
     if(root==NULL)
       return NULL;
     else if(root->lchild==NULL && root->rchild==NULL)
       return root;
     else
     {
         Node *t=root,*p;
         while(t!=NULL)
         {
             p=t;
             t=t->lchild;
         }
         return p;
     }
 }
 Node* maxElement()
 {
     if(root==NULL)
       return NULL;
     else if(root->lchild==NULL && root->rchild==NULL)
       return root;
     else
     {
         Node *t=root,*p;
         while(t!=NULL)
         {
             p=t;
             t=t->rchild;
         }
         return p;
     }
 }
 int min()
 {
     Node *t=minElement();
     if(t==NULL)
       return -1;
    return t->data;
 }
 int max()
 {
     Node *t=maxElement();
     if(t==NULL)
       return -1;
    return t->data;
 }
 Node* SearchNode(int value)
 {
     if(root==NULL)
       return NULL;
     else
     {
         Node *t=root;
         while(t!=NULL)
         {
            if(t->data>value)
              t=t->lchild;
            else if(t->data<value)
              t=t->rchild;
            else if(t->data==value)
             return t;
         }
         return NULL;
     }
 }
 
 void Delete(int value)
{
  if(root==NULL)
   cout<<"empty";
  else
  {
    Node *t=root,*p=root;
    while(t!=NULL)
    {
       if(t->data > value)
       {
           p=t;
           t=t->lchild;
       }
       else if(t->data < value)
       {
         p=t;
         t=t->rchild;
       }
       else if(t->data == value && t->lchild == NULL && t->rchild == NULL )
       {
          if(p->data > t->data)
             {
               p->lchild=NULL;
               delete t;
               return;
             }
          else
          {
            p->rchild=NULL;
            delete t;
            return;
          }
          
       }
       else if(t->data == value &&(t->lchild!=NULL && t->rchild==NULL))
       {
         if(p->data > t->data)
         {
           p->lchild = t->lchild;
           delete t;
           return;
         }
         else
         {
           p->rchild = t->lchild;
           delete t;
           return;
         }
         
       }
       else if(t->data == value &&(t->lchild==NULL && t->rchild!=NULL))
       {
         if(p->data > t->data)
         {
           p->lchild = t->rchild;
           delete t;
           return;
         }
         else
         {
           p->rchild = t->rchild;
           delete t;
           return;
         }
       }
       else if(t->data == value &&(t->lchild!=NULL && t->rchild!=NULL))
       {
         if(t->lchild->rchild==NULL)
         {
           Node *m=t->lchild;
           t->lchild=m->lchild;
           t->data=m->data;
           delete m;
         }
         else{
         Node *m,*n=t->lchild;
         while(n->rchild!=NULL)
         {
           m=n;
           n=n->rchild;
         }
         m->rchild=NULL;
         t->data = n->data;
         delete n;
         return;
         }
       }
    }
  }
  
}
 int CountNode()
 {
   if(root==NULL)
      return -1;
    else
    {
      int c=0;
      queue<Node*> q;
      Node *t;
      q.push(root);
      while(!q.empty())
      {
          t=q.front();
          q.pop();
          c++;
          if(t->lchild!=NULL)
             q.push(t->lchild);
          if(t->rchild!=NULL)
             q.push(t->rchild);
      }
      return c;
    }
 }
};
int main()
{
    BinarySearchTree B;
    B.insert(20);
    B.insert(30);
    B.insert(28);
    B.insert(12);
    B.insert(40);
    B.insert(50);
    B.insert(17);
    B.LevelOrder();
    cout<<endl;
    B.Delete(20);
    B.LevelOrder();

}