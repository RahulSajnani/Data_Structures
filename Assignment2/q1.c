#include<stdio.h>
#include<stdlib.h>
long long int m=1000000007;
typedef struct node
{
	long int x;
	struct node *nxt;
}node;
typedef struct delist
{
	long int x,y,z;
}list;
void merge(long long int s,long long int e)
{
	long int i,j,k=s;
	for(i=s;i<=((s+e)/2);i++)
		t1[i-s]=array[i];
	for(j=(s+e)/2+1;j<=e;j++)
		t2[j-1-(s+e)/2]=array[j];
	i=0;j=0;
	while(i<=(s+e)/2-s&&j<=e-(s+e)/2-1)
	{
		if(t1[i].d==t2[j].d)
		{
			if(t1[i].s>t2[j].s)
				array[k++]=t1[i++];
			else
				array[k++]=t2[j++];
		}
		else if(t1[i].d<t2[j].d)
			array[k++]=t1[i++];
		else
			array[k++]=t2[j++];
	}
	while(i<=(s+e)/2-s)
		array[k++]=t1[i++];
	while(j<=e-(s+e)/2-1)
		array[k++]=t2[j++];
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
list d[100005];
node *ptr[100005];
char wtn[100005][100005];
long int n;
int e[100005];
long long int power(long int a,long int b)
{
	long int c=b;
	long long int an=1,p=a%m;
	while(c>0)
	{
		if(c%2==1)
			an=((an%m)*p)%m;
		p=(p*p)%m;
		c=c/2;
	}
	return an;
}
//void modexp(long long int a,long int b)
//{

void deletenode(node *q,long int p,long int num)
{
	//long int k=0;
	if(q==NULL)return;
	//printf("%ld %ld\n",p,num);
	if(e[num]==1)
	{
		n--;
		e[num]=0;
	}
	node *i;
	i=q;
	while(i!=NULL)
	{
		if(i->x!=p)
		{
			deletenode(ptr[i->x],num,i->x);
		}
		i=i->nxt;
	} 
	return;
}
int main()
{
	long int a,b,c,i,k=0;
	long long int ans;
	scanf("%ld",&n);
	k=n;
	for(i=0;i<n-1;i++)
	{
		scanf("%ld %ld %ld",&a,&b,&c);
		d[i].x=a;d[i].y=b;d[i].z=c;
		node *temp=(node*)malloc(sizeof(node));
		temp->x=b;
		temp->nxt=ptr[a];
		ptr[a]=temp;
		node *temp2=(node*)malloc(sizeof(node));
		temp2->x=a;
		temp2->nxt=ptr[b];
		ptr[b]=temp2;
		if(wtn[c][a]!='1'&&wtn[c][a]!='2')
			wtn[c][a]='1';
		else if(wtn[c][a]=='1')
			wtn[c][a]='2';
		if(wtn[c][b]!='1'&&wtn[c][b]!='2')
			wtn[c][b]='1';
		else if(wtn[c][b]=='1')
			wtn[c][b]='2';
		e[a]=1;
		e[b]=1;
	}
	for(i=0;i<k-1;i++)
	{
		/*if(wtn[d[i].z][d[i].y]=='2'&&wtn[d[i].z][d[i].x]=='2')
		{
			e[d[i].x]=0;
			deletenode(ptr[d[i].x],d[i].y);
			e[d[i].y]=0;
			deletenode(ptr[d[i].y],d[i].x);
			n--;
			n--;
		}*/
		//printf("%ld %ld %ld\n",d[i].x,d[i].y,d[i].z);
		if(wtn[d[i].z][d[i].x]=='2')
		{
		//			e[d[i].y]=0;
			deletenode(ptr[d[i].y],d[i].x,d[i].y);
		}
		if(wtn[d[i].z][d[i].y]=='2')
		{
	//		if(e[d[i].x]==1)
	//			e[d[i].x]=0;
			deletenode(ptr[d[i].x],d[i].y,d[i].x);
		}
	}
	//ans=power(3,2);
	printf("%ld",n);
	return 0;
}
