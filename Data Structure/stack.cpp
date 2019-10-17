//stack using array
#include<iostream>
using namespace std;
class Stack
{
    private:
    int capacity;
    int t;
    int *s;
    public:
    Stack()
    {
        capacity=10;
        t = -1;
        s=new int[capacity];
    }
    Stack(int cap)
    {
        capacity =cap;
        t=-1;
        s=new int[capacity];
    }
    ~Stack()
    {
        delete s;
    }
    void push(int data);
    void pop();
    int top();
    bool empty();
    int size();

};
void Stack:: push(int data)
{
    t++;
    if(t < capacity)
      s[t]=data;
}
void Stack:: pop()
{
    if(t>-1)
       t--;
}
int Stack:: top()
{
    if(t>-1 && t<capacity)
      return s[t];
}
bool Stack::empty()
{
    if(t == -1)
     return true;
    return false;
}
int Stack::size()
{
    return t+1;
}
int main()
{
  Stack S(10);
  S.push(23);
  S.push(67);
  S.push(34);
  S.push(25);
  S.push(212);
  S.push(278);
  S.push(78);
    cout<<endl<<S.top();
}