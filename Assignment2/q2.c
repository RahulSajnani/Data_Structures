#include<stdio.h>
#include<stdlib.h>
long int n,tr,tb;
long long int ans,m=1000000007;
typedef struct rbtree
{
	long int x,r,b,e;
	struct rbtree *ptr;
}rbtree;
int rb[100005];
rbtree pt[100005];
//rbtree a[100005];
void dfsn(rbtree *t,long int p)
{
	long long int re,be;
	if(t==NULL)return;
	rbtree *i;
	i=t;
	//printf("%ld",i->ptr->x);
	/*if(i->ptr==NULL)
	{
		printf("%ld",t->x);
		if(rb[t->x]==0)
			t->r++;
		else
			t->b++;
		return;
	}*/
	while(i->ptr!=NULL)
	{	
		if(i->ptr->x!=p)
		{
			//printf("%ld ",i->ptr->x);
			dfsn(&pt[i->ptr->x],t->x);
			t->r+=pt[i->ptr->x].r;
			t->b+=pt[i->ptr->x].b;
			//printf("%lld\n",ans);
			//if(pt[i->ptr->x].r)
			re=(((pt[i->ptr->x].r)%m)*(tr-pt[i->ptr->x].r)%m)%m;
			be=(((pt[i->ptr->x].b)%m)*(tb-pt[i->ptr->x].b)%m)%m;
			ans=(ans%m+(((i->ptr->e)%m)*(re+be)%m)%m)%m;
		//	printf("%lld %ld %ld %ld\n",ans,i->ptr->e,pt[i->ptr->x].r,pt[i->ptr->x].b);	
		}
			i=i->ptr;
	}
	if(rb[t->x]==0)
		t->r++;
	else
		t->b++;
	//ans+=(t->ptr->e)*((pt[i->ptr->x].r)*(tr-pt[i->ptr->x].r)+(pt[i->ptr->x].b)*(tb-pt[i->ptr->x].b));
	//printf("%ld %ld %ld\n",t->x,t->r,t->b);

}		
int main()
{
	long int i,x1,x2,ed;
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&rb[i]);
		if(rb[i]==1)
			tb++;
		else
			tr++;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%ld %ld %ld",&x1,&x2,&ed);
		rbtree *temp=(rbtree*)malloc(sizeof(rbtree));
		temp->x=x2;
		temp->e=ed;
		temp->r=0;
		temp->b=0;
		temp->ptr=pt[x1].ptr;
		pt[x1].x=x1;
		pt[x1].ptr=temp;
               	rbtree *temp2=(rbtree*)malloc(sizeof(rbtree));
	        temp2->x=x1;
		temp2->e=ed;
		temp2->r=0;
	        temp2->b=0;
	        temp2->ptr=pt[x2].ptr;
		pt[x2].x=x2;
                pt[x2].ptr=temp2;
	}
	//printf("%ld",pt[1].ptr->x);
	dfsn(&pt[1],1);
	printf("%lld",ans);
	return 0;
}






