#include<bits/stdc++.h>
using namespace std;

typedef struct segarr{
    long long int l,r;
    vector<long long int> a;
}segarr;
segarr stre[1000005];
long long int n,q,st[100005],en[100005],it=0,an;
vector<long long int>u[100005];
vector<long long int>dfarr,dst;

void dfs(vector<long long int> v,long long int curr,long long int p,long long int d)
{
    long long int i;
    dst.push_back(d);
    dfarr.push_back(curr);
    st[curr]=it;
    it++;
    /*if(v.size()==1)
    {
        en[curr]=it-1;
        return;
    }*/
    for(i=0;i<v.size();i++)
    {
        if(v[i]!=p)
        {
            //it++;
            dfs(u[v[i]],v[i],curr,d+1);
        }
    }
    //it++;
    dst.push_back(d);
    dfarr.push_back(curr);
    en[curr]=it;
    it++;
}

void build(long long int p,int i,int e)
{
  if(i==e)
  {
    stre[p].a.push_back(dst[i]);
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
    //cout<<stre[p].l<<" "<<stre[p].r<<" "<<dst[i]<<"\n";
    merge(stre[2*p].a.begin(),stre[2*p].a.end(),stre[2*p+1].a.begin(),stre[2*p+1].a.end(),back_inserter(stre[p].a));
    return ;
   }
}

void query(long long int p,long long int no,long long int di)
{
  //`cout<<"\n"<<t->l<<" "<<t->r;
  if(st[no]>stre[p].r||en[no]<stre[p].l)
    return;
  else if(st[no]<=stre[p].l&&en[no]>=stre[p].r)
  {  
    an+=(((upper_bound(stre[p].a.begin(),stre[p].a.end(),dst[st[no]]+di)-stre[p].a.begin())-((lower_bound(stre[p].a.begin(),stre[p].a.end(),dst[st[no]]+di))-stre[p].a.begin())));  
    return; 
  }
  else
  {
    query(2*p,no,di); 
    query(2*p+1,no,di);
    return;
  }    
}
int main()
{
    long long int i,a,b;
    cin>>n>>q;
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        u[a].push_back(b);
        u[b].push_back(a);
    }
    dfs(u[1],1,-1,0);
    build(1,0,dst.size()-1);
    /*
    for(i=0;i<dfarr.size();i++)
        cout<<dfarr[i]<<" ";
    cout<<"\n";    
    for(i=0;i<dst.size();i++)
        cout<<dst[i]<<" ";   
    cout<<"\n";    
    for(i=1;i<=n;i++)
        cout<<st[i]<<" ";
    cout<<"\n";
    for(i=1;i<=n;i++)
        cout<<en[i]<<" ";*/         
    for(i=0;i<q;i++)
    {
        an=0;
        cin>>a>>b;
        query(1,a,b);
        cout<<an/2<<"\n";
    }
    return 0;
}