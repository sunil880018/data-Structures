#include<bits/stdc++.h>
using namespace std;

void uni(int *s,int u,int v)
{
      if(s[u]==-1 && s[v]==-1)
     {
         s[v]=s[v]+s[u];
         s[u]=v;
     }
    else if(s[u] > s[v])
    {
        s[v]=s[v]+s[u];
        s[u]=v;
    }
    else if(s[v]>s[u])
    {
        s[u]=s[u]+s[v];
        s[v]=u;
    }
}

int find(int *s,int u)
{
    int x=u;
    while(s[x]>0)
    {
        x=s[x];
    }
    return x;
}
void add(int *s,int u,int v)
{
    int x=find(s,u);
    int y=find(s,v);
    uni(s,x,y);
}
int count_friend(int *s,int u)
{
    if(s[u]<-1)
     return (-s[u])-1;
    else if(s[u]==-1)
     return 0;
    else
    {
        while(s[u]>0)
         {
             u=s[u];
         }
         return (-s[u])-1;
    }
    
}
int main()
{
    int a[11];
    for(int i=0;i<11;i++)
       a[i]=-1;
    add(a,4,3);
    add(a,2,4);
    add(a,2,3);
    cout<<count_friend(a,4);
}