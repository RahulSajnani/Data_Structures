#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    vector<long long int>a;
    int l,r;
}node;

node vec[400010];
long long int arr[1000005],n,an;

void build(long long int p,int i,int e)
{
  if(i==e)
  {
    vec[p].a.push_back(arr[i]);
    vec[p].l=e;
    vec[p].r=i;
    return;
  }
  else
  {
    build(2*p,i,(i+e)/2);
    build(2*p+1,(i+e)/2+1,e);
    vec[p].l=vec[2*p].l;
    vec[p].r=vec[2*p+1].r;
    merge(vec[2*p].a.begin(),vec[2*p].a.end(),vec[2*p+1].a.begin(),vec[2*p+1].a.end(),back_inserter(vec[p].a));
    return ;
   }
}

void query(long long int p,int ql,int qr,long long int x)
{
  //`cout<<"\n"<<t->l<<" "<<t->r;
  if(ql>vec[p].r||qr<vec[p].l)
    return;
  else if(ql<=vec[p].l&&qr>=vec[p].r)
  {
    an+=upper_bound(vec[p].a.begin(),vec[p].a.end(),x)-vec[p].a.begin();  
    return; 
  }
  else
  {
    query(2*p,ql,qr,x); 
    query(2*p+1,ql,qr,x);
    return;
  }    
}

int main()
{
  int i,q,l,r;
  long long int x;
  cin>>n;
  for(i=1;i<=n;i++)
    cin>>arr[i];
  build(1,1,n);  
  cin>>q;
  for(i=0;i<q;i++)
  {
    an=0;  
    cin>>l>>r>>x;
    query(1,l,r,x);
    cout<<an<<"\n";
  }
  return 0;
}