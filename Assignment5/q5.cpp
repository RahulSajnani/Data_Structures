#include<bits/stdc++.h>
using namespace std;

struct node{
    long long int ed,v1,v2;
};

long long int n,m,k,ans[100005],an=-1;
int ex[100005],vi[100005],lel[100005];
vector<node> ptr[100005];
struct compar{
    bool operator()(const node &a,const node &b)
    {
        return a.ed>=b.ed;
    }
};
priority_queue<node,vector<node>,compar>Heap;

void ansdj()
{
    long long int i,op=0;
    node t;
    for(i=0;i<ptr[0].size();i++)
        Heap.push(ptr[0][i]);
    while(!Heap.empty())
    {
        t=Heap.top();
        Heap.pop();
        //cout<<t.v1<<" "<<t.v2<<" "<<t.ed<<"\n";
        if(lel[t.v1]==0&&ex[t.v2]==1)
        {
            lel[t.v1]=1;
            continue;
        }
        if(lel[t.v1]==1&&ex[t.v2]==1)
        {
            an=t.ed;
            return;
        }
        if(vi[t.v1]==1&&vi[t.v2]==0)
        {
                vi[t.v2]=1;
                ans[t.v2]=t.ed;
                for(i=0;i<ptr[t.v2].size();i++)
                {
                    if(ptr[t.v2][i].v2!=t.v1)
                    {
                        ptr[t.v2][i].ed+=ans[t.v2];
                        Heap.push(ptr[t.v2][i]);
                    }
                }
        }
    }
}

int main()
{
    an=-1;
    long long int a,b,c,i;
    cin>>n>>m>>k;
    node tmp;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        tmp.ed=c;
        tmp.v1=a;
        tmp.v2=b;
        ptr[a].push_back(tmp);
        tmp.v1=b;
        tmp.v2=a;
        ptr[b].push_back(tmp);
    }
    for(i=0;i<k;i++)
    {
        cin>>a;
        ex[a]=1;
    }
    if(ex[0]==1||n==1)
    {
        cout<<0;
        return 0;
    }
    vi[0]=1;
    ansdj();
    cout<<an;
  return 0;
}