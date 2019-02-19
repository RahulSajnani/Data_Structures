#include<stdio.h>
#include<stdlib.h>
long long int n;
long long int an=0,l=1000000007;
typedef struct arr
{
	long long int x,y,z;
}arr;
arr ele[100005],t1[50005],t2[50005];
typedef struct node
{
	long long int x,wt;
	struct node *nxt;
}no;
no *ptr[100005];
int e[100005];
long long int power(long long int a,long long int b,long long int m)
{
	long long int c=b;
	long long int and=1,p=a%m;
	while(c>0)
	{
		if(c%2==1)
			and=((and%m)*p)%m;
		p=(p*p)%m;
		c=c/2;
	}
	return and;
}
void merge(long long int s,long long int e)
{
	long int i,j,k=s;
	for(i=s;i<=((s+e)/2);i++)
		t1[i-s]=ele[i];
	for(j=(s+e)/2+1;j<=e;j++)
		t2[j-1-(s+e)/2]=ele[j];
	i=0;j=0;
	while(i<=(s+e)/2-s&&j<=e-(s+e)/2-1)
	{
		if(t1[i].z==t2[j].z)
		{
			if(t1[i].x>t2[j].x)
				ele[k++]=t1[i++];
			else
				ele[k++]=t2[j++];
		}
		else if(t1[i].z<t2[j].z)
			ele[k++]=t1[i++];
		else
			ele[k++]=t2[j++];
	}
	while(i<=(s+e)/2-s)
		ele[k++]=t1[i++];
	while(j<=e-(s+e)/2-1)
		ele[k++]=t2[j++];
	return;
}
void mergesort(long int s,long int e)
{
	if(s==e)return;
	mergesort(s,(s+e)/2);
	mergesort(((s+e)/2)+1,e);
	merge(s,e);
	return;
}
void deletenode(no *t,long long  int in,long long int p)
{
	if(t==NULL)
		return;
	no *i;
	i=t;
	//printf("%ld ",in); 
	if(e[in]==1)
	{
		e[in]=0;
		n--;
	}
	while(i!=NULL)
	{
		if(i->x!=p)
		{
			//if(e[i->x]==1)
				deletenode(ptr[i->x],i->x,in);
		}
		i=i->nxt;
	}
}
void ans(no *t,long long int in,long long int p,long long int w)
{
	if(t==NULL)return;
	no *i;
	i=t;
	//printf("%ld ",in);
	while(i!=NULL)
	{
		if(i->x!=p)
		{
			if(i->nxt!=NULL&&i->wt==i->nxt->wt)
			{
				deletenode(ptr[i->x],i->x,in);
				deletenode(ptr[i->nxt->x],i->nxt->x,in);
			}
			if(i->wt==w)
			{
				deletenode(ptr[i->x],i->x,in);
				deletenode(ptr[p],p,in);
			}
			else
				ans(ptr[i->x],i->x,in,i->wt);
		}
		i=i->nxt;
	}
}
void dfs(no *t)
{
	no *i;
	i=t;
	while(i!=NULL)
	{
		if(e[i->x]==1)
		{

			dfs(ptr[i->nxt]);
		i=i->nxt;
	}
}
int main()
{
	long long int i,k=n,a,b,c;
	no *t;
	scanf("%lld",&n);
	k=n;
	for(i=0;i<n-1;i++)
		scanf("%lld %lld %lld",&ele[i].x,&ele[i].y,&ele[i].z);
	mergesort(0,n-2);
	for(i=0;i<n-1;i++)
	{
		a=ele[i].x;b=ele[i].y;c=ele[i].z;
		no *temp=(no*)malloc(sizeof(no));
		temp->x=b;
		e[a]=1;
		e[b]=1;
		temp->wt=c;
		temp->nxt=ptr[a];
		ptr[a]=temp;
		no *t2=(no*)malloc(sizeof(no));
		t2->x=a;
		t2->wt=c;
		t2->nxt=ptr[b];
		ptr[b]=t2;
	}
	for(i=1;i<=k;i++)
	{
		//if(e[i]==1)
		//{
			t=ptr[i];
			while(t!=NULL)
			{
				//printf("whil");
				if(t->x!=i)
				{
					if(t->nxt!=NULL&&t->wt==t->nxt->wt)
					{
						//printf("%lld %lld",t->x,t->nxt->x);
						if(e[t->x]==1)
							deletenode(ptr[t->x],t->x,i);

						if(e[t->nxt->x]==1)
							deletenode(ptr[t->nxt->x],t->nxt->x,i);
							if(n==0)break;
					}
				}
				t=t->nxt;	
			}
		//}
	}
	//printf("lol");
	//ans(ptr[b],b,-1,-1);
	//printf("%lld",n);
	an=power(n,n,l-1);
	an=power(n,an,l);	
	printf("%lld",an);
	return 0;
}





