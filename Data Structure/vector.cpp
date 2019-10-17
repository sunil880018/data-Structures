// vector
#include <iostream>
#define C 100000000
#define INT_MAX 999999
#define INT_MIN -999999
using namespace std;

//class vector
class vector
{
    private:
    int lastIndex;
    int capacity;
    int *array;

    public:
    // parameterized Constructor
    vector(int size)
    {
        lastIndex = -1;
        if(size <= C)
        {
            capacity = size;
            array = new int[size];
        }   
        else
        {
           array = new int[C];
           capacity = 1;
        }
        
    }
    vector() // default Constructor
    {
        lastIndex = -1;
        capacity = 1;
        array = new int[capacity];
    }
    ~vector() // destructor
    {
        delete array;
    }
    // All operations
    void push_back(int data);
    int pop();
    int update(int i,int data);
    int size();
    void sort();
    int min();
    int max();
    int front();
    int back();
    int At(int i);//display at index i
    void fill(int i);//initialize whole array
    void display();
    bool empty();
    int v_capacity();

};

void vector::push_back(int data)
{
    lastIndex++;
    if(lastIndex < capacity)
      array[lastIndex]=data;
    else if(lastIndex == capacity)
    {
        if(2*capacity <= 100000000)
           {
               int *p =new int[2*capacity];
               for(int i=0;i<lastIndex;i++)
               {
                   p[i]=array[i];
               }
               capacity = 2*capacity;
               delete array;
               array=p;
               array[lastIndex]=data;
           }
    }
}
int vector::pop()
{
    if(lastIndex==-1)
      return -1;
    else
    {
        int temp=array[lastIndex];
        lastIndex--;
        if(lastIndex==(capacity/2)-1)
        {
           int *p=new int[lastIndex+1];
           for(int i=0;i<=lastIndex;i++)
             p[i]=array[i];
             delete array;
             array=p;
            capacity = lastIndex+1;
        }
        return temp;
    }
    
}
int vector::update(int i,int data)
{
    if(i>= 0 && i<=lastIndex)
    {
       array[i]=data;
       return 1;
    }
   return 0;
}

int vector::size()
{
    return lastIndex+1;
}

void vector::sort() // count sort
{
    int h[100000]={0},j=0;
    for(int i=0;i<=lastIndex;i++)
       h[array[i]]++;
    for(int i=0;i<100000;i++)
      {
          if(h[i]>0)
          {
              while(h[i]--)
              {
                  array[j++]=i;
              }
          }
      }
}

int vector::min()
{
    if(!empty())
    {
       int m=INT_MAX;
           for(int i=0;i<=lastIndex;i++)
              if(m > array[i])
                  m = array[i];
      return m;
    }
    return INT_MAX;
}

int vector::max()
{
    if(!empty())
    {
       int m=INT_MIN;
           for(int i=0;i<=lastIndex;i++)
              if(m < array[i])
                  m = array[i];
      return m;
    }
    return INT_MIN;   
}

int vector::front()
{
    if(lastIndex>-1)
       return array[0];
    return INT_MIN;
}

int vector::back()
{
    if(lastIndex>-1)
       return array[lastIndex];
    return INT_MAX;
}

int vector::At(int i)
{
    if(i>-1 && i<=lastIndex)
       return array[i];
    return INT_MAX;
}

void vector::fill(int i)
{
    for(int j=0;j<capacity;j++)
      array[j]=i;
}

bool vector::empty()
{
    if(lastIndex==-1)
      return true;
    return false;
}

void vector::display()
{
    for(int i=0;i<capacity;i++)
     cout<<array[i]<<" ";
}

int vector::v_capacity()
{
    return capacity;
}
int main()
{
  vector A(1);
  A.push_back(10);
  A.push_back(34);
  A.push_back(45);
  A.push_back(10);
  A.push_back(89);
  A.push_back(40);
  for(int i=0;i<A.size();i++)
    cout<<A.At(i)<<" ";
    cout<<endl;
    A.pop();
    cout<<endl;
   for(int i=0;i<A.size();i++)
    cout<<A.At(i)<<" ";
    cout<<endl;
 cout<<A.v_capacity();
  
}