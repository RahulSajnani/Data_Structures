#include<stdio.h>
#include<stdlib.h>
long long int ans,m=1000000007,P;
typedef struct avl
{
	long long int val,h,nodes,hash;
	struct avl *left,*right,*parent;
}avl;
avl *a;
long long int power(long long int a,long long int b)
{
	long long int c=b;
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
void ll(avl *root)
{
	//printf("%lld %lld",root->val,root->h);
	avl *t1,*t2;
	t1=root->left;
	t2=t1->right;
	t1->right=root;
	root->left=t2;
	if(t2!=NULL)
		t2->parent=root;
	if(root->parent!=NULL&&root->parent->val<=t1->val)
	{
		root->parent->right=t1;
		t1->parent=root->parent;
	}
	else if(root->parent!=NULL)
	{
		root->parent->left=t1;
		t1->parent=root->parent;
	}
	else
	{
		a=t1;
		t1->parent=NULL;
	}
	root->parent=t1;
	if(root->left!=NULL&&root->right!=NULL)
	{
		if(root->right->h>root->left->h)
			root->h=root->left->h+1;
		else 
			root->h=root->right->h+1;
		root->nodes=root->left->nodes+root->right->nodes+1;
		root->hash=(root->left->hash+((root->val+root->right->hash)%m*power(P,root->left->nodes+1))%m)%m;

	}
	else if(root->right!=NULL)
	{
		root->h=root->right->h+1;
		root->nodes=root->right->nodes+1;
		root->hash=((root->val+root->right->hash)%m*P)%m;
	}
	else if(root->left!=NULL)
	{
		root->h=root->left->h+1;
		root->nodes=root->left->nodes+1;
		root->hash=(root->left->hash+(root->val*power(P,root->nodes))%m)%m;
	}
	else
	{
		root->h=1;
		root->nodes=1;
		root->hash=(root->val*P)%m;
	}
	if(t1->left!=NULL)
	{
		if(t1->right->h>t1->left->h)
			t1->h=t1->right->h;
		else
			t1->h=t1->left->h;
		t1->nodes=t1->left->nodes+t1->right->nodes+1;
		t1->hash=(t1->left->hash+((t1->val+t1->right->hash)%m)*(power(P,t1->left->nodes+1)%m)%m)%m;	
	}
	else
	{
		t1->h=t1->right->h+1;
		t1->nodes=t1->right->nodes+1;
		t1->hash=(((t1->val+t1->right->hash)%m)*P)%m;
	}

}
void lr(avl *root)
{
	avl *t1,*t2;
	t1=root->left;
	t2=t1->right;
	t1->right=t2->left;
	if(t2->left!=NULL)
		t2->left->parent=t1;
	t2->left=t1;
	t1->parent=t2;
	root->left=t2;
	t2->parent=root;
	if(t1->left!=NULL&&t1->right!=NULL)
	{
		if(t1->right->h>t1->left->h)
			t1->h=t1->left->h+1;
		else 
			t1->h=t1->right->h+1;
		t1->nodes=t1->left->nodes+t1->right->nodes+1;
		t1->hash=(t1->left->hash+(t1->val+t1->right->hash)%m*power(P,t1->left->nodes+1))%m;

	}
	else if(t1->right!=NULL)
	{
		t1->h=t1->right->h+1;
		t1->nodes=t1->right->nodes+1;
		t1->hash=((t1->val+t1->right->hash)%m*P%m)%m;
	}
	else if(t1->left!=NULL)
	{
		t1->h=t1->left->h+1;
		t1->nodes=t1->left->nodes+1;
		t1->hash=(t1->left->hash+(t1->val*power(P,t1->nodes))%m)%m;
	}
	else
	{
		t1->h=1;
		t1->nodes=1;
		t1->hash=(t1->val*P)%m;
	}
	/*if(t1->left!=NULL&&t1->right!=NULL)
	{
		if(t1->left->h>t1->right->h)
			t1->h=t1->left->h+1;
		else
			t1->h=t1->right->h+1;
	}
	else 

	if(t2->right!=NULL)
	{
		if(t2->right->h>t2->left->h)
			t2->h=t2->right->h+1;
		else
			t2->h=t2->left->h+1;
	}
	else
		t2->h=t2->left->h+1;
	
	if(t2->right!=NULL)
	{
		if(t2->right->h>t2->left->h)
			t2->h=t2->right->h;
		else
			t2->h=t2->left->h;
		t2->nodes=t2->left->nodes+t2->right->nodes+1;
		t2->hash=(t2->left->hash+((t2->val%m)*(power(P,t2->left->nodes+1)%m))%m+t2->right->hash*(power(P,t2->left->nodes+1)%m)%m)%m;	
	}
	else
	{
		t2->h=t2->left->h+1;
		t2->nodes=t2->left->nodes+1;
		t2->hash=(t2->left->hash+((t2->val%m)*(power(P,t2->nodes))%m)%m)%m;
	}*/
	ll(root);
}
void rr(avl *root)
{
	//printf("%lld %lld",root->val,root->h);
	avl *t1,*t2;
	t1=root->right;
	t2=t1->left;
	t1->left=root;
	root->right=t2;
	if(t2!=NULL)
		t2->parent=root;
	if(root->parent!=NULL&&root->parent->val<=t1->val)
	{
		root->parent->right=t1;
		t1->parent=root->parent;
	}
	else if(root->parent!=NULL)
	{
		root->parent->left=t1;
		t1->parent=root->parent;
	}
	else
	{
		a=t1;
		t1->parent=NULL;
	}
	root->parent=t1;
	if(root->left!=NULL&&root->right!=NULL)
	{
		if(root->right->h>root->left->h)
			root->h=root->left->h+1;
		else 
			root->h=root->right->h+1;
		root->nodes=root->left->nodes+root->right->nodes+1;
		root->hash=(root->left->hash+((root->val+root->right->hash)%m*power(P,root->left->nodes+1))%m)%m;

	}
	else if(root->right!=NULL)
	{
		root->h=root->right->h+1;
		root->nodes=root->right->nodes+1;
		root->hash=((root->val+root->right->hash)%m*P%m)%m;
	}
	else if(root->left!=NULL)
	{
		root->h=root->left->h+1;
		root->nodes=root->left->nodes+1;
		root->hash=(root->left->hash+(root->val*power(P,root->nodes))%m)%m;
	}
	else
	{
		root->h=1;
		root->nodes=1;
		root->hash=(root->val*P)%m;
	}
	if(t1->right!=NULL)
	{
		if(t1->right->h>t1->left->h)
			t1->h=t1->right->h;
		else
			t1->h=t1->left->h;
		t1->nodes=t1->left->nodes+t1->right->nodes+1;
		t1->hash=(t1->left->hash+(((t1->val)+t1->right->hash)%m*(power(P,t1->left->nodes+1))%m)%m)%m;	
	}
	else
	{
		t1->h=t1->left->h+1;
		t1->nodes=t1->left->nodes+1;
		t1->hash=(t1->left->hash+((t1->val)*(power(P,t1->nodes)))%m)%m;
	}

}
void rl(avl *root)
{
	avl *t1,*t2;
	t1=root->right;
	t2=t1->left;
	t1->left=t2->right;
	if(t2->right!=NULL)
		t2->right->parent=t1;
	t2->right=t1;
	t1->parent=t2;
	root->right=t2;
	t2->parent=root;
	if(t1->left!=NULL&&t1->right!=NULL)
	{
		if(t1->right->h>t1->left->h)
			t1->h=t1->left->h+1;
		else 
			t1->h=t1->right->h+1;
		t1->nodes=t1->left->nodes+t1->right->nodes+1;
		t1->hash=(t1->left->hash+((t1->val+t1->right->hash)%m*power(P,t1->left->nodes+1))%m)%m;

	}
	else if(t1->right!=NULL)
	{
		t1->h=t1->right->h+1;
		t1->nodes=t1->right->nodes+1;
		t1->hash=((t1->val+t1->right->hash)%m*P)%m;
	}
	else if(t1->left!=NULL)
	{
		t1->h=t1->left->h+1;
		t1->nodes=t1->left->nodes+1;
		t1->hash=(t1->left->hash+(t1->val*power(P,t1->nodes))%m)%m;
	}
	else
	{
		t1->h=1;
		t1->nodes=1;
		t1->hash=(t1->val*P)%m;
	}
	/*if(t1->left!=NULL&&t1->right!=NULL)
	{
		if(t1->left->h>t1->right->h)
			t1->h=t1->left->h+1;
		else
			t1->h=t1->right->h+1;
	}
	else if(t1->left!=NULL)
		t1->h=t1->left->h+1;
	else if(t1->right!=NULL)
		t1->h=t1->right->h+1;
	else
		t1->h=1;
	
	if(t2->left!=NULL)
	{
		if(t2->right->h>t2->left->h)
			t2->h=t2->right->h+1;
		else
			t2->h=t2->left->h+1;
	}
	else
		t2->h=t2->right->h+1;
	*
	if(t2->left!=NULL)
	{
		if(t2->right->h>t2->left->h)
			t2->h=t2->right->h;
		else
			t2->h=t2->left->h;
		t2->nodes=t2->left->nodes+t2->right->nodes+1;
		t2->hash=(t2->left->hash+((t2->val%m)*(power(P,t2->left->nodes+1)%m))%m+t2->right->hash*(power(P,t2->left->nodes+1)%m)%m)%m;	
	}
	else
	{
		t2->h=t2->right->h+1;
		t2->nodes=t2->right->nodes+1;
		t2->hash=(((t2->val%m)*P%m)%m+(t2->right->hash)%m)%m;
	}*/
	rr(root);
}
void balance(avl *root)
{
	avl *i;
	i=root;
	while(i!=NULL)
	{
		if(i->left!=NULL&&i->right!=NULL)
		{
			if(i->left->h>=i->right->h)
			{
				if(i->left->h-i->right->h<=1)
				{
					i->h=i->left->h+1;
				//	i->nodes=i->left->nodes+i->right->nodes+1;
					i->nodes=((i->left->nodes%m*i->right->nodes%m)%m*P)%m;
					if(i->right->val!=i->val)
						i->hash=(i->left->hash+((i->val+i->right->hash)%m*(i->left->nodes*P)%m)%m)%m;
					else
					{
						if(i->right->left!=NULL)
							i->hash=i->left->hash+((i->right->hash*i->left->nodes)%m*P)%m+(((i->val*i->right->left->nodes)%m*(P*P)%m)%m*i->left->nodes)%m;
						else
							i->hash=(i->left->hash+((i->right->hash*i->left->nodes)%m*P)%m+(((i->val*P)%m*P)%m*i->left->nodes)%m)%m;		
					}					
		//			i->hash=(i->left->hash+((i->val+i->right->hash)%m*power(P,i->left->nodes+1))%m)%m;
				}
				else
				{
					if(i->left->right!=NULL&&i->left->left!=NULL)
					{
						if(i->left->right->h>i->left->left->h)
							 lr(i);
						else
							 ll(i);
					}
					else if(i->left->left==NULL&&i->left->right!=NULL)
							 lr(i);
					else if(i->left->right==NULL&&i->left->left!=NULL)
							 ll(i);
				}
			}
			else
			{
				if(i->left->h<=i->right->h)
				{
					if(i->right->h-i->left->h<=1)
					{
						i->h=i->right->h+1;
						//i->nodes=i->left->nodes+i->right->nodes+1;
						//i->hash=(i->left->hash+((i->val+i->right->hash)%m*power(P,i->left->nodes+1))%m)%m;
						i->nodes=((i->left->nodes%m*i->right->nodes%m)%m*P)%m;
						if(i->right->val!=i->val)
							i->hash=(i->left->hash+((i->val+i->right->hash)%m*(i->left->nodes*P)%m)%m)%m;
						else
						{
							if(i->right->left!=NULL)
								i->hash=i->left->hash+((i->right->hash*i->left->nodes)%m*P)%m+(((i->val*i->right->left->nodes)%m*(P*P)%m)%m*i->left->nodes)%m;
							else
								i->hash=(i->left->hash+((i->right->hash*i->left->nodes)%m*P)%m+(((i->val*P)%m*P)%m*i->left->nodes)%m)%m;			
						}					
					}
					else
					{
						if(i->right->right!=NULL&&i->right->left!=NULL)
						{
							if(i->right->right->h>i->right->left->h)
								rr(i);
							else
								rl(i);
						}
						else if(i->right->left==NULL&&i->right->right!=NULL)
								rr(i);
						else if(i->right->right==NULL&&i->right->left!=NULL)
								rl(i);
					}
				}
			}
		}
		else if(i->left==NULL&&i->right!=NULL)
		{
			//printf("%lld %lld",i->val,i->h);
			if(i->right->h==1)
			{
				//printf("right->h=1");
				i->h=i->right->h+1;
				i->nodes=(i->right->nodes*P)%m;
				if(i->val!=i->right->val)
					i->hash=((i->val+i->right->hash)%m*P)%m;
				else
					i->hash=(((i->val*P)%m+i->right->hash)%m*P)%m
				i=i->parent;
				continue;
			}
			if(i->right->right!=NULL&&i->right->left!=NULL)
			{	
				if(i->right->right->h>i->right->left->h)
					rr(i);
				else
					rl(i);
			}
			else if(i->right->left==NULL&&i->right->right!=NULL)
				rr(i);
			else if(i->right->right==NULL&&i->right->left!=NULL)
				rl(i);
		}
		else if(i->right==NULL&&i->left!=NULL)
		{
			if(i->left->h==1)
			{
				i->h=i->left->h+1;
				i->nodes=(i->left->nodes*P)%m;
				i->hash=(i->left->hash+((i->val*P)%m*i->nodes)%m);
				i=i->parent;
				continue;
			}
			if(i->left->right!=NULL&&i->left->left!=NULL)
			{
				if(i->left->right->h>i->left->left->h)
					lr(i);
				else
					ll(i);
			}
			else if(i->left->left==NULL&&i->left->right!=NULL)
				lr(i);
			else if(i->left->right==NULL&&i->left->left!=NULL)
				ll(i);
		}
		else
		{
			i->h=1;
			i->nodes=P;
			i->hash=(i->val*P)%m;
			//printf("i->right&&i->left=NULL %lld",a->h);
		}
		i=i->parent;
	}
}
void insert(long long int x)
{
	avl *i;
	i=a;
	avl *temp=(avl*)malloc(sizeof(avl));
	temp->val=x;
	temp->h=1;
	temp->nodes=1;
	temp->hash=(temp->val%m*P%m)%m;
	temp->parent=NULL;
	temp->left=NULL;
	temp->right=NULL;
	if(i==NULL)
	{
		a=temp;
		return;
	}
	while(i!=NULL)
	{
		if(x>=i->val)
		{
			if(i->right!=NULL)
				i=i->right;
			else
			{
				i->right=temp;
				temp->parent=i;
				break;
			}
		}
		else
		{
			if(i->left!=NULL)
				i=i->left;
			else
			{
				i->left=temp;
				temp->parent=i;
				break;
			}
		}
	}
	balance(temp);
}
void delete(avl *node)
{
	avl *i;int op;
	i=node;
	if(i->left==NULL&&i->right==NULL)
	{
		//printf("%lld",i->val);
		if(i->parent!=NULL)
		{
			if(i->parent->left!=NULL&&i->parent->right!=NULL)
			{
				if(i->parent->left->val==i->val)
					i->parent->left=NULL;
				else
					i->parent->right=NULL;
			}
			else if(i->parent->left!=NULL)
				i->parent->left=NULL;
			else 
				i->parent->right=NULL;

		i=i->parent;
		}
		else
		{
			a=NULL;
			return;
		}
		free(node);
		balance(i);
		return;
	}
	else if(i->left==NULL)
	{
		i=i->right;
		while(i->left!=NULL)
			i=i->left;
		node->val=i->val;
		delete(i);
	}
	else if(i->right==NULL)
	{
		i=i->left;
		while(i->right!=NULL)
			i=i->right;
		node->val=i->val;
		delete(i);
	}
	else
	{
		if(i->left->h>=i->right->h)
		{
			op=0;
			i=i->left;
		}
		else
		{
			op=1;
			i=i->right;
		}
		if(op==0)
		{
			while(i->right!=NULL)
				i=i->right;
			node->val=i->val;
			delete(i);
		}
		else
		{
			while(i->left!=NULL)
				i=i->right;
			node->val=i->val;
			delete(i);
		}
	}
}
void deletenode(long long int x)
{
	avl *i;
	i=a;
	while(i!=NULL)
	{
		if(i->val==x)
		{
			delete(i);
			break;
		}
		else if(i->val<x)
			i=i->right;
		else
			i=i->left;
	}
}
/*void calcans(avl *no,long long int rep)
{
	if(no==NULL)return;
	avl *i;
	i=no;
	long int r;
	if(i->right!=NULL&&i->right->val==i->val)
	{
		r=rep+1;
		calcans(i->right,r);
	}
	else
	{
		calcans(i->right,1);
		ans=(((ans%m+((rep)%m*(i->val%m))%m)%m)*power(P,rep)%m)%m;
	}
	calcans(i->left,1);
}*/
int main()
{
	long long int Q,i=0,x,g=0;
	char ch;
	scanf("%lld %lld",&Q,&P);
	for(i=0;i<Q;++i)
	{
		scanf(" %c",&ch);
		if(ch=='A')
		{
			scanf(" %lld",&x);
			insert(x);
			//g=1;
			//printf("%lld %lld",a->val,a->h);
			//if(a->left!=NULL)
			//	printf("%lld %lld",a->left->val,a->left->h);
		}
		else if(ch=='D')
		{
			scanf(" %lld",&x);
			deletenode(x);
			//g=1;
		//	printf("%lld %lld",a->val,a->h);
		}
		else 
		{
			/*if(g==1)
			{
				ans=0;
				calcans(a,1);
				g=0;
			}*/
			if(a!=NULL)
				printf("%lld\n",a->hash);
			else
				printf("0\n");
		}
		//if(ch=='h'||ch=='H'||ch=='a'||ch=='A'||ch=='d'||ch=='D')
	}
	return 0;
}
	
