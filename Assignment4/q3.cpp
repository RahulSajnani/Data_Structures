#include<bits/stdc++.h>
using namespace std;

long long int n,m,k,indeg[100005],rindeg[100005],dep[100005];
vector<long long int> g[100005],gr[100005],req,ans;
int vi[100005],rvi[100005],cyc;
priority_queue<long long int ,vector<long long int>,greater<long long int> > Heap;

void revdfs(long long int curr,long long int p)
{
    if(cyc==1)return;
    long long int i;
    dep[curr]=1;
    rvi[curr]=1;
    for(i=0;i<gr[curr].size();i++)
    {
        if(gr[curr][i]!=p&&rvi[gr[curr][i]]!=1&&rvi[gr[curr][i]]!=2)
            revdfs(gr[curr][i],curr);
        if(rvi[gr[curr][i]]==1)
            cyc=1;    
    }
    rvi[curr]=2;
}

void fans()
{
    long long int i,t;
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0&&dep[i]==1)
            Heap.push(i);
        vi[i]=1;    
    }
    while(!Heap.empty())
    {
        t=Heap.top();
        ans.push_back(Heap.top());
        Heap.pop();
        for(i=0;i<g[t].size();i++)
        {
            indeg[g[t][i]]--;
            if(indeg[g[t][i]]==0&&dep[g[t][i]]==1)
            {
                vi[g[t][i]]=1;
                Heap.push(g[t][i]);
            }    
        }
    }
}

int main()
{
    long long int i,a,b;
    cin>>n>>m>>k;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        gr[b].push_back(a);
        rindeg[a]++;
        indeg[b]++;
    }
    for(i=0;i<k;i++)
    {
        cin>>a;
        req.push_back(a);
    }
    for(i=0;i<req.size();i++)
    {
        if(rvi[req[i]]!=2)
            revdfs(req[i],-1);
    }
    if(cyc==1)
        cout<<"GO HOME RAJAS";
    else
    {
        fans();
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
    }    
    return 0;
}