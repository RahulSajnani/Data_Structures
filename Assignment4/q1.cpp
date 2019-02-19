#include<bits/stdc++.h>
using namespace std;

typedef struct Mat 
{
  long long int m11,m12,m21,m22;
}mat;

typedef struct node 
{
  mat a;
  struct node *lc,*rc;
  long long l,r;
}node;

node *root=NULL;
long long int n,mod=1000000007;
mat an,id,a1,a2,mul;
mat arr[100005];

node* build(long long int i,long long int e)
{
  if(i==e)
  {
    node *temp=(node*)malloc(sizeof(node));
    temp->a=arr[e];
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
    temp->a.m11=(((temp->lc->a.m11)%mod*(temp->rc->a.m11)%mod)%mod+((temp->lc->a.m12)%mod*(temp->rc->a.m21)%mod)%mod)%mod;
    temp->a.m12=(((temp->lc->a.m11)%mod*(temp->rc->a.m12)%mod)%mod+((temp->lc->a.m12)%mod*(temp->rc->a.m22)%mod)%mod)%mod;
    temp->a.m21=(((temp->lc->a.m21)%mod*(temp->rc->a.m11)%mod)%mod+((temp->lc->a.m22)%mod*(temp->rc->a.m21)%mod)%mod)%mod;
    temp->a.m22=(((temp->lc->a.m21)%mod*(temp->rc->a.m12)%mod)%mod+((temp->lc->a.m22)%mod*(temp->rc->a.m22)%mod)%mod)%mod;
    return temp;
  }
}

void query(node *t,long long int ql,long long int qr)
{
  if(t==NULL)return;
  //cout<<"\n"<<t->l<<" "<<t->r;
  if(ql>t->r||qr<t->l)
    return;
  else if(ql<=t->l&&qr>=t->r)
  {
    //cout<<"\n"<<t->l<<" "<<t->r;
    mul.m11=(((an.m11)%mod*(t->a.m11)%mod)%mod+((an.m12)%mod*(t->a.m21)%mod)%mod)%mod;
    mul.m12=(((an.m11)%mod*(t->a.m12)%mod)%mod+((an.m12)%mod*(t->a.m22)%mod)%mod)%mod;
    mul.m21=(((an.m21)%mod*(t->a.m11)%mod)%mod+((an.m22)%mod*(t->a.m21)%mod)%mod)%mod;
    mul.m22=(((an.m21)%mod*(t->a.m12)%mod)%mod+((an.m22)%mod*(t->a.m22)%mod)%mod)%mod;
    an=mul;
    return; 
  }
  else
  {
    query(t->lc,ql,qr); 
    query(t->rc,ql,qr);
    return;
  }    
  /*if(t->l<=ql&&t->r>qr)
  {
    query(t->lc,ql,qr); 
    query(t->rc,ql,qr);
  }
  else if(t->r>=qr&&t->l<ql)
  {
    query(t->lc,ql,qr);
    query(t->rc,ql,qr);
  }
  else if((t->l==ql&&t->r<=qr)||(t->l>=ql&&t->r==qr)||(t->l>ql&&t->r<qr))
  {
    mat mul;
    //cout<<"\n"<<t->l<<" "<<t->r;
    mul.m11=(((an.m11)%mod*(t->a.m11)%mod)%mod+((an.m12)%mod*(t->a.m21)%mod)%mod)%mod;
    mul.m12=(((an.m11)%mod*(t->a.m12)%mod)%mod+((an.m12)%mod*(t->a.m22)%mod)%mod)%mod;
    mul.m21=(((an.m21)%mod*(t->a.m11)%mod)%mod+((an.m22)%mod*(t->a.m21)%mod)%mod)%mod;
    mul.m22=(((an.m21)%mod*(t->a.m12)%mod)%mod+((an.m22)%mod*(t->a.m22)%mod)%mod)%mod;
    an=mul;
  }
  else if(qr>=t->l&&qr<=t->r)
    query(t->lc,ql,qr);
  else if(t->l<=ql&&ql<=t->r)
    query(t->rc,ql,qr);  
  return;*/ 
}

void update(node *t,long long int i)
{
  //cout<<" "<<t->l<<" "<<t->r;
  if(t==NULL)return;
  if(t->l==i&&t->r==i)
  {
    //cout<<"lol";
    t->a=arr[i];
  }
  else if(t->l<=i&&t->r>=i)
  {
   //cout<<t->l<<" "<<t->r<<"\n";  
   update(t->lc,i);
   update(t->rc,i);
   a1=t->lc->a;
   a2=t->rc->a;
   t->a.m11=(((a1.m11)%mod*(a2.m11)%mod)%mod+((a1.m12)%mod*(a2.m21)%mod)%mod)%mod;
   t->a.m12=(((a1.m11)%mod*(a2.m12)%mod)%mod+((a1.m12)%mod*(a2.m22)%mod)%mod)%mod;
   t->a.m21=(((a1.m21)%mod*(a2.m11)%mod)%mod+((a1.m22)%mod*(a2.m21)%mod)%mod)%mod;
   t->a.m22=(((a1.m21)%mod*(a2.m12)%mod)%mod+((a1.m22)%mod*(a2.m22)%mod)%mod)%mod; 
  } 
  return; 
}

int main()
{
  id.m11=1;
  id.m12=0;
  id.m21=0;
  id.m22=1;
  long long int i,q,l,r,p;
  int op;
  cin>>n;
  for(i=1;i<=n;i++)
    cin>>arr[i].m11>>arr[i].m12>>arr[i].m21>>arr[i].m22;
  build(1,n);  
  cin>>q;
  for(i=0;i<q;i++)
  {
    an=id;
    cin>>op;
    if(op==1)
    {
      cin>>l>>r;
      if(1<=l&&l<=r&&r<=n)
      {
        query(root,l,r);
        cout<<"\n"<<an.m11<<" "<<an.m12<<" "<<an.m21<<" "<<an.m22;
      }
      else
        cout<<"\n0 0 0 0";
    }
    else if(op==2)
    {
      cin>>p;
      cin>>arr[p].m11>>arr[p].m12>>arr[p].m21>>arr[p].m22;
      update(root,p);
    }
  }
  return 0;
}

