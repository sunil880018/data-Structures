#include<bits/stdc++.h>
using namespace std;
class BinaryTree
{
 private:
     struct Node
     {
         Node *lchild;
         Node *rchild;
         int data;
     };
     Node *root;
public:
    BinaryTree()
    {
        root = NULL;
    }
    void insert(int value)
    {
        if(root==NULL)
        {
            Node *t = new Node();
            t->data = value;
            t->lchild = NULL;
            t->rchild = NULL;
            root=t;
            return;
        }
        else
        {
            queue<Node*> Q;
            Q.push(root);
            Node *t;
            while(!Q.empty())
            {
                t=Q.front();
              Q.pop();
              if(t->lchild!=NULL)
                Q.push(t->lchild);
              else
              {
                   Node *n = new Node();
                   n->data = value;
                   n->lchild = NULL;
                   n->rchild = NULL;
                   t->lchild=n;
                   return;
              }
              if(t->rchild!=NULL)
                Q.push(t->rchild);
              else
              {
                   Node *n = new Node();
                   n->data = value;
                   n->lchild = NULL;
                   n->rchild = NULL;
                   t->rchild=n;
                   return;
              }
            }
        }
    }
    void InOrder()
    {
        Node *t;
        if(root==NULL)
         cout<<"empty\n";
        else
        {
           t=root;
           stack<Node*> s;
           while(t!=NULL||!s.empty())
           {
                 if (t!=NULL)
                 {
                     s.push(t);
                     t=t->lchild;
                 }
                 else
                 {
                     t=s.top();
                     s.pop();
                     cout<<t->data<<" ";
                     t=t->rchild;
                 }
           }
        }
    }
    void preOrder()
    {
        stack<Node*> s;
        if(root==NULL)
         cout<<"empty\n";
        else
        {
            Node *t=root;
            while (t!=NULL||!s.empty())
            {
                if(t!=NULL)
                 {
                     cout<<t->data<<" ";
                     s.push(t);
                     t=t->lchild;
                 }
                 else
                 {
                     t=s.top();
                     s.pop();
                     t=t->rchild;
                 }
            }
        }
    }
    void levelOrder()
    {
          if(root==NULL)
            cout<<"empty\n";
          else
          {
              queue<Node*> q;
              Node* t;
              q.push(root);
            while (!q.empty())
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
    int CountNodes()
    {
          if(root==NULL)
            return 0;
          else
          {
              queue<Node*> q;
              Node* t;
              q.push(root);
              int counter=0;
            while (!q.empty())
            {
               t=q.front();
               q.pop();
               counter++;
               if(t->lchild!=NULL)
                 q.push(t->lchild);
               if(t->rchild!=NULL)
                 q.push(t->rchild);
            }
              return counter;
          }
    }
    int max()
    {
      if(root==NULL)
        return -1;
      else
      {
        queue<Node*> q;
        q.push(root);
        Node *t;
        int max = root->data;
        while(!q.empty())
        {
          t=q.front();
          q.pop();
          if(t->lchild!=NULL)
          {
             if(t->lchild->data > max)
                 max = t->lchild->data;
             q.push(t->lchild);
          }
          if(t->rchild != NULL)
          { 
             if(t->rchild->data > max)
                 max = t->rchild->data;
             q.push(t->rchild);
          } 
          
        }
        return max;
      }
    }
    int min()
    {
      if(root==NULL)
        return -1;
      else
      {
        queue<Node*> q;
        q.push(root);
        Node *t;
        int min = root->data;
        while(!q.empty())
        {
          t=q.front();
          q.pop();
          if(t->lchild!=NULL)
          {
             if(t->lchild->data < min)
                 min = t->lchild->data;
             q.push(t->lchild);
          }
          if(t->rchild != NULL)
          { 
             if(t->rchild->data < min)
                 min = t->rchild->data;
             q.push(t->rchild);
          } 
        }
        return min;
      }
    }
    Node* search(int value)
    {
      if(root==NULL)
         return NULL;
      else
      {
        queue<Node*> q;
        q.push(root);
        Node *t;
        while(!q.empty())
        {
          t=q.front();
          q.pop();
          if(t->data==value)
             return t;
          if(t->lchild!=NULL)
            q.push(t->lchild);
          if(t->rchild!=NULL)
            q.push(t->rchild);
        }
        return NULL;
      }
    }
    int countLeaves()
    {
      if(root==NULL)
         return -1;
      else
      {
        queue<Node*> q;
        q.push(root);
        int l=0;
        Node *t;
        while (!q.empty())
        {
          t=q.front();
          q.pop();
          if(t->lchild ==NULL && t->rchild == NULL)
             l++;
          else
          {
            if(t->lchild!=NULL)
               q.push(t->lchild);
            if(t->rchild!=NULL)
               q.push(t->rchild);
          }
          
        }
        return l;
      }
      
    }
    bool same(BinaryTree A)
    {
      if(root== NULL && A.root==NULL)
        return true;
      else
      {
        queue<Node*>q1,q2;
        if(root!=NULL)
           q1.push(root);
        if (A.root!=NULL)
           q2.push(A.root);
        Node *t1=root,*t2=A.root;
        while(!q1.empty() && !q2.empty())
         {
           t1 = q1.front();
           q1.pop();
           t2 = q2.front();
           q2.pop();
           if(t1->data != t2->data)
             return false;
           if(t1->lchild!=NULL)
              q1.push(t1->lchild);
           if(t1->rchild!=NULL)
              q1.push(t1->rchild);
           if(t2->lchild!=NULL)
              q2.push(t2->lchild);
           if(t2->rchild!=NULL)
              q2.push(t2->rchild);
         }
         if(q1.empty()&& q2.empty())
              return true;
            return false;
      }
      
    }
};
int main()
{
    BinaryTree B,B1;
    B.insert(3);
    B.insert(30);
    B.insert(20);
    B.insert(12);
    B.insert(25);
    B.insert(9);
    B.insert(80);
    B.insert(40);
    B.insert(100);

    B1.insert(3);
    B1.insert(30);
    B1.insert(20);
    B1.insert(12);
    B1.insert(25);
    B1.insert(9);
    B1.insert(80);
    B1.insert(40);
    B1.insert(100);
    cout<<B.same(B1);
}

bool isBST(Node* root) {
    stack<Node*> s;
    int a[10000],i=0;
    while(root!=NULL||!s.empty())
    {
        if(root!=NULL)
        {
          s.push(root);
          root=root->left;
        }
        else
        {
            root=s.top();
            s.pop();
            a[i++]=root->data;
            root=root->right;
        }
    }
    for(int j=0;j<i-1;j++)
       if(a[j]>a[j+1])
         return false;
    return true;
}
