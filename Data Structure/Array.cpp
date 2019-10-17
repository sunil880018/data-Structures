// static Array Adt
#include <iostream>
#define C 100000
#define INT_MAX 999999
#define INT_MIN -999999
using namespace std;

//class of Array Adt 
class Array
{
    private:
    int lastIndex;
    int capacity;
    int *array;

    public:
    // parameterized Constructor
    Array(int size)
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
           capacity = C;
        }
        
    }
    Array() // default Constructor
    {
        lastIndex = -1;
        capacity = C;
        array = new int[capacity];
    }
    ~Array() // destructor
    {
        delete array;
    }
    // All operations
    void push_back(int data);
    void insertAtIndex(int i,int data);
    int pop();
    int deleteAtIndex(int i);
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

};
void Array::push_back(int data)
{
    lastIndex++;
    if(lastIndex < capacity)
      array[lastIndex]=data;
}

void Array::insertAtIndex(int i,int data)
{
   if(i>-1 && i<capacity-1 && i <=lastIndex)
   {
       for(int j=lastIndex;j>=i;j--)
          array[j+1]=array[j];
        array[i]=data;
        lastIndex++;
   }
   else
   {
       lastIndex++;
       array[lastIndex]=data;
   }
}

int Array::pop()
{
    if(!empty())
    {
        lastIndex--;
        return array[lastIndex+1];
    }
    return -1;
}

int Array::deleteAtIndex(int i)
{
    if(i>= 0 && i <=lastIndex)
    {
         for(int j=i+1;j<=lastIndex;j++)
           array[j-1]=array[j];
         lastIndex--;
    }
    return -1;
}

int Array::update(int i,int data)
{
    if(i>= 0 && i<=lastIndex)
    {
       array[i]=data;
       return 1;
    }
   return 0;
}

int Array::size()
{
    return lastIndex+1;
}

void Array::sort() // count sort
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

int Array::min()
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

int Array::max()
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

int Array::front()
{
    if(lastIndex>-1)
       return array[0];
    return INT_MIN;
}

int Array::back()
{
    if(lastIndex>-1)
       return array[lastIndex];
    return INT_MAX;
}

int Array::At(int i)
{
    if(i>-1 && i<=lastIndex)
       return array[i];
    return INT_MAX;
}

void Array::fill(int i)
{
    for(int j=0;j<capacity;j++)
      array[j]=i;
}

bool Array::empty()
{
    if(lastIndex==-1)
      return true;
    return false;
}

void Array::display()
{
    for(int i=0;i<capacity;i++)
     cout<<array[i]<<" ";
}
int main()
{
  Array A(10);
  A.push_back(33);
  A.push_back(70);
  A.push_back(34);
  A.push_back(55);
  A.push_back(13);
  A.push_back(10);
  A.push_back(10);
  A.push_back(10);
  for(int i=0;i<A.size();i++)
    cout<<A.At(i)<<" ";
    cout<<endl;
  A.sort();
  for(int i=0;i<A.size();i++)
    cout<<A.At(i)<<" ";
}