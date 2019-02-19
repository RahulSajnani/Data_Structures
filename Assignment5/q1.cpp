#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    long long int ed,v1,v2;
}node;
struct compar{
    bool operator()(const node &a,const node &b)
    {
        return a.ed>=b.ed;
    }
};
long long int n,m,s,t1,a,b,an;
int vi[100005],path[100005];
long long int ans[100005];
vector<node > ptr[100005];

priority_queue<node,vector<node >,compar  >Heap;

void ansdj()
{
    long long int i,op=0;
    node t;
    for(i=0;i<ptr[s].size();i++)
        Heap.push(ptr[s][i]);
    while(!Heap.empty())
    {
        op=0;
        t=Heap.top();
        Heap.pop();
        if(((path[t.v1]==2&&t.ed>=b)||(path[t.v1]==1&&(t.ed<=a||t.ed>=b)))&&t.v2==t1)
        {
            an=t.ed;
            return;
        }
        if(vi[t.v1]==1&&vi[t.v2]==0)
        {
            if(t.ed<=a&&(path[t.v1]==1||path[t.v1]==0))
            {
                vi[t.v2]=1;
                ans[t.v2]=t.ed;
                path[t.v2]=1;
                op=1;
            }
            else if(t.ed>=b&&path[t.v1]==1)
            {
                vi[t.v2]=1;
                ans[t.v2]=t.ed;
                path[t.v2]=2;
                op=1;
            }
            if(op==1)
            {
                //cout<<t.v1;
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
}


int main()
{
    long long int i,x,y,e;
    node tmp;
    cin>>n>>m;
    cin>>s>>t1;
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>e;
        tmp.v2=y;
        tmp.v1=x;
        tmp.ed=e;
        ptr[x].push_back(tmp);
        tmp.v2=x;
        tmp.v1=y;
        ptr[y].push_back(tmp);
    }
    an=-1;
    path[s]=0;ans[s]=0;vi[s]=1;
    cin>>a>>b;
    if(s==t1)
    {
        cout<<0;
        return 0;
    }
    ansdj();
    cout<<an;
    return 0;
}