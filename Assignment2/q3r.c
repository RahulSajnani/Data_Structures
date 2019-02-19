#include<stdio.h>
typedef struct s1
{
	long long int d,t,s;
}s1;
long int it;
s1 heap[100005],array[100005],t1[50005],t2[50005];
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
void Push(s1 in)
{
	s1 temp;
	++it;
	heap[it]=in;
	long int i=it;
	//printf("%ld %ld %ld %ld\n",heap[i].d,heap[i].t,heap[i].s,it);
	while(i>1)
	{
		if(heap[i].s>heap[i/2].s)
		{
			temp=heap[i];
			heap[i]=heap[i/2];
			heap[i/2]=temp;
			i=i/2;
		}
		else
			break;
	}
	//printf("%ld %ld %ld %ld\n",heap[0].d,heap[0].t,heap[0].s,it);
	 return;
}
void del(long long int N,long long int D)
{
	long long int j=0,t,s,d;
	s1 temp;
	t=heap[1].t;
	s=heap[1].s;
	d=heap[1].d;
	if(heap[1].d<=D)
	{
		if(heap[1].t>1)
		{
			heap[1].t=(heap[1].t)-1;
			heap[1].d=heap[1].d+1;
			return ;
		}
		else
		{
			heap[1]=heap[it];
			j=1;
			while(j<=it)
			{
				if(2*j<=it)
				{
					if(heap[2*j+1].s>heap[2*j].s&&(2*j+1)<=it)
					{
						temp=heap[j];
						heap[j]=heap[2*j+1];
						heap[2*j+1]=temp;
						j=2*j+1;
					}
					else
					{
						temp=heap[j];
						heap[j]=heap[2*j];
						heap[2*j]=temp;
						j=2*j;
					}
				}
				else
					j=2*j;
			}
			if(it>0)
				it--;	
		}
		return;
	}
}
long long int ans[10];
int main()
{
	long long int T,N,D,i,j,p,k,small;
	scanf("%lld",&T);
	for(i=0;i<T;i++)
	{
		k=0;
		it=0;
		scanf("%lld %lld",&N,&D);
		p=D;
		for(j=0;j<N;j++)
			scanf("%lld %lld %lld",&array[j].d,&array[j].t,&array[j].s);
		mergesort(0,N-1);
		//printf("lololol%ld",N);
		//for(j=0;j<N;j++)
		//	printf("%ld %ld %ld\n",array[j].d,array[j].t,array[j].s);
		for(j=0;j<D;j++)
		{
			while(k<N)
			{
				if(array[k].d>j+1)
					break;
				Push(array[k]);
				k++;
			}
			if(p>0)
			{
				del(N,D);
				p--;
			}
				
		}
		//printf("%ld it",it);
		//for(j=1;j<=N;j++)
		//	printf("%lld %lld %lld\n",heap[j].d,heap[j].t,heap[j].s);
		
		//for(j=1;j<=it;j++)
		//	printf("%lld %lld %lld\n",heap[j].d,heap[j].t,heap[j].s);
		for(j=1;j<=it;j++)
			ans[i]+=((heap[j].s)*(heap[j].t));
		for(j=k;j<N;j++)
			ans[i]+=array[k].s*array[k].t;
	}
	for(i=0;i<T;i++)
	printf("%lld \n",ans[i]);
	return 0;
}



		

