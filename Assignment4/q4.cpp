#include<bits/stdc++.h>
using namespace std;

typedef struct node 
{
  vector<long long int> a;
  struct node *lc,*rc;
  int l,r;
}node;

node *root=NULL;
long long int arr[1000005],n,an;

node* build(int i,int e)
{
  if(i==e)
  {
    node *temp=(node*)malloc(sizeof(node));
    temp->a.push_back(arr[e]);
    temp->lc=NULL;
    temp->rc=NULL;
    temp->l=e;
    temp->r=e;
    return temp;
  }
  else
  {
    node *temp=(node*)malloc(sizeof(node));
    if(root==NULL)
      root=temp;
    temp->lc=build(i,(i+e)/2);
    temp->rc=build((i+e)/2+1,e);
    temp->l=temp->lc->l;
    temp->r=temp->rc->r;
    merge(temp->lc->a.begin(),temp->lc->a.end(),temp->rc->a.begin(),temp->rc->a.end(),back_inserter(temp->a));
    return temp;
  }
}

/*long long int binsearch(vector <long long int> v,long long int x)
{
    int s,e,m;
    s=0;e=v.size();
    while(s<=e)
    {
        if(s==e)break;
        m=(s+e)/2;
        //cout<<v[m]<<" "<<m<<"\n";
        if(v[m]<=x)
            s=s+1;
        else if(v[m]>x)
            e=e-1;
            
    }
    return s;
}*/
void query(node *t,int ql,int qr,long long int x)
{
  if(t==NULL)return;
  //`cout<<"\n"<<t->l<<" "<<t->r;
  if(ql>t->r||qr<t->l)
    return;
  else if(ql<=t->l&&qr>=t->r)
  {
    an+=upper_bound(t->a.begin(),t->a.end(),x)-t->a.begin();  
    return; 
  }
  else
  {
    query(t->lc,ql,qr,x); 
    query(t->rc,ql,qr,x);
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
  build(1,n);  
  cin>>q;
  for(i=0;i<q;i++)
  {
    an=0;  
    cin>>l>>r>>x;
    query(root,l,r,x);
    cout<<an<<"\n";
  }
  return 0;
}

