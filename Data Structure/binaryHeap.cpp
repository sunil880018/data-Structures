//Binary Max Heap
#include<iostream>
using namespace std;
class Heap
{
 private:
   int capacity;
   int *h;
   int index;
   public:
   Heap(int cap)
   {
       capacity = cap;
       index=-1;
       h= new int[capacity];
   }
   Heap()
   {
       capacity=10;
       index=-1;
       h=new int[capacity];
   }
   ~Heap()
   {
       delete h;
   }
   void push(int data);
   void pop();
   int size();
   int front();
   bool isheap();
   void display();
};
void Heap::push(int data)
{
  if(index==-1)
  {
      index++;
      h[index]=data;

  }
  else if(index+1 < capacity)
  {
     index++;
     h[index]=data;
     int t=index;
     int temp;
     while(t>0)
     {
         if(h[(t-1)/2]  < h[t])
         {
            temp=h[t];
            h[t]=h[(t-1)/2];
            h[(t-1)/2]=temp;
            t=(t-1)/2;
         }
         else
           break;
     }
  }
}
void Heap::pop()
{
    if(index==0)
      index=-1;
    else
    {
        h[0]=h[index];
        index--;
        int i=0;
        while(i<index-1)
        {
           if(h[i*2+1] > h[i*2+2])
            {
                int temp=h[i];
                h[i]=h[i*2+1];
                h[i*2+1]=temp;
                i=i*2+1;
            }
            else
            {
                int temp=h[i];
                h[i]=h[i*2+2];
                h[i*2+2]=temp;
                i=i*2+2;
            }
        }
    }
}
void Heap::display()
{
    for(int i=0;i<=index;i++)
     cout<<h[i]<<" ";
}
int Heap::size()
{
    return index+1;
}
int Heap::front()
{
    if(index>-1)
      return h[0];
    return -1;
}
bool Heap::isheap()
{
    if(index>-1)
    {
       int i=index;
       while((i-2/2)>=0)
       {
           if(h[i]<h[(i-2)/2])
             i--;
           else
            return false;
       }
       return true;
    }
    else
    return false;
}

int main()
{
 Heap h;

 h.push(45);
 h.push(89);
 h.push(3);
 h.push(100);
 h.display();
 h.heap_sort();
 cout<<endl;
 h.display();
}