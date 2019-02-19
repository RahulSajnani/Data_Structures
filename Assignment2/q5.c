#include<stdio.h>
#include<stdlib.h>
typedef struct gear{
	long int x,y,r,k;
	struct gear *next;
}g;
g a[1005];
int adj[1005],ro[1005];
long int n,d=0;
void dfs(g *ch,g *pa,int rot)
{
	g *i=NULL;
	//if(ch!=NULL)
	//{
	adj[ch->k]=1;
	ro[ch->k]=rot;
	i=ch->next;
	//}
	while(i!=NULL)
	{
		if(pa!=NULL&&i->k!=pa->k)
		{
			//printf("%ld",i->k);
			if(adj[i->k]==1)
			{
				printf("lol");
				if(ro[ch->k]==ro[i->k])
					d=-1;
			}	
			if(i->k==n-1&&d!=-1)
				d=1;
			if(adj[i->k]!=1)
			{
				if(rot==0)
					dfs(&a[i->k],ch,1);
				else
					dfs(&a[i->k],ch,0);
			}
		}
		i=i->next;
	}
}
int main()
{
	 long int i,j;
	 scanf("%ld",&n);
	 for(i=0;i<n;i++)
	 {
		 scanf("%ld %ld %ld",&a[i].x,&a[i].y,&a[i].r);
		 a[i].k=i;
		 a[i].next=NULL;
	 }
	 for(i=0;i<n;i++)
	 {
		 for(j=0;j<n;j++)
		 {
			 if(i!=j&&((((a[i].x-a[j].x)*(a[i].x-a[j].x))+((a[i].y-a[j].y)*(a[i].y-a[j].y)))==((a[i].r+a[j].r)*(a[i].r+a[j].r))))
			 {
				 g *temp=(g*)malloc(sizeof(g));
				 temp->x=a[j].x;
				 temp->y=a[j].y;
				 temp->r=a[j].r;
				 temp->k=j;
				 temp->next=a[i].next;
				 a[i].next=temp;
			//	 printf("%ld  %ld\n",i,j);
			 }
		 }
	 }
	 dfs(&a[0],&a[0],0);
	 //printf("%ld",a[1].next->k);
	 if(d==-1)
		 printf("The input gear cannot move.");
	 else if(d==0)
		 printf("The input gear is not connected to the output gear.");
	 else
	 {
		 if(ro[n-1]==ro[0])
			 printf("%ld:%ld",a[n-1].r,a[0].r);
		 else
			 printf("-%ld:%ld",a[n-1].r,a[0].r);
	 }
	 return 0;
}

