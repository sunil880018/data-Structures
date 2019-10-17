#include<iostream>
using namespace std;
struct node//creating node
{
    long long int data;
    node *p=NULL;
};
//count digit
int count_digit(int num)
{
    int count=0;
    while(num>9)
    {
        num=num/10;
        count++;
    }
    count++;
    return count;
}
//sorting
void radix_sort(long long int *arr,int n)
{
    int max=count_digit(arr[0]);
  for(int i=1;i<n;i++)
  {
      int temp=count_digit(arr[i]);
        if(max<temp)
            max=temp;
  }

  int d=1;
  while (max--)
  {
      int r;
      node *bin[10]={NULL};
      for(int i=0;i<n;i++)
      {
          r=(arr[i]/d)%10;
          node *n=new node();
          n->data=arr[i];
          if(bin[r]==NULL)
              bin[r]=n;
          else
          {
              node *t=bin[r];
              while(t->p!=NULL)
                t=t->p;
              t->p=n;
          } 
      }
      int j=0;
      for(int i=0;i<10;i++)
      {
          
          if(bin[i]!=NULL)
          {
             node *t=bin[i];
            while(t!=NULL)
           {
               arr[j++]=t->data;
               t=t->p;
           }
          }  
      }
      for(int i=0;i<10;i++)
      {
          if(bin[i]!=NULL)
          {
              node*t=bin[i];
              while(t->p!=NULL)
              {
                  t=t->p;
                  delete bin[i];
                  bin[i]=t;
              }
              delete bin[i];
              bin[i]=NULL;
          }
      }
      d=d*10;
  }
  
}
int main()
{
    long long int  a[] = {9999999,9999,121252545,878675,99999999,88888888888};
    radix_sort(a,6);
    for(int i=0;i<6;i++)
     cout<<a[i]<<" ";
}