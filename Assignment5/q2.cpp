#include<bits/stdc++.h>
using namespace std;

typedef struct segtree
{
    long long int l,r,toadd;
}seg;
seg stre[500005];
vector<long long int>dfarr,ptr[200005];
long long int st[200005],en[200005],val[200005];
long long int n,m,it=0,an,va;


void dfs(vector<long long int> v,long long int curr,long long int p)
{
    long long int i;
    dfarr.push_back(curr);
    st[curr]=it;
    it++;
    for(i=0;i<v.size();i++)
    {
        if(v[i]!=p)
            dfs(ptr[v[i]],v[i],curr);
    }
    dfarr.push_back(curr);
    en[curr]=it;
    it++;
}

void build(long long int p,int i,int e)
{
  if(i==e)
  {
    stre[p].l=e;
    stre[p].r=i;
    return;
  }
  else
  {
    build(2*p,i,(i+e)/2);
    build(2*p+1,(i+e)/2+1,e);
    stre[p].l=stre[2*p].l;
    stre[p].r=stre[2*p+1].r;
    return ;
   }
}

void update(long long int p,long long int no)
{
  if(st[no]>stre[p].r||en[no]<stre[p].l)
    return;
  else if(st[no]<=stre[p].l&&en[no]>=stre[p].r)
  {  
    stre[p].toadd+=va;  
    return; 
  }
  else
  {
      
    va=stre[p].toadd;  
    update(2*p,no); 
    update(2*p+1,no);
    return;
  }
}    

void query(long long int p,long long int no)
{
  //`cout<<"\n"<<t->l<<" "<<t->r;
  if(st[no]>stre[p].r||en[no]<stre[p].l)
    return;
  else if(st[no]<=stre[p].l&&en[no]>=stre[p].r) 
    return; 
  else
  {  
    an=stre[p].toadd;  
    query(2*p,no); 
    query(2*p+1,no);
    return;
  }    
}
int main()
{
    long long int i,a,b,op,va;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>val[i];
    for(i=0;i<n-1;i++)
        {
            cin>>a>>b;
            ptr[a].push_back(b);
            ptr[b].push_back(a);
        }
    dfs(ptr[1],1,-1);
    build(1,0,dfarr.size()-1);        
    for(i=0;i<m;i++)
    {
        an=0;
        cin>>op;
        if(op==1)
        {
            cin>>a>>va;
            val[a]+=va;
            update(1,a);
        }
        else
        {
            cin>>a;
            query(1,a);
            cout<<val[a]-an;
        }
    }    
    return 0;
}