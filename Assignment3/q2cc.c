#include<stdio.h>
#include<stdlib.h>
typedef struct tr
{
	char c;
	struct tr *sib;
	struct tr *ch;
	long long int ln;
	long long int e;
}tr;
tr *a;
//long long int and[200005];
long long int n=0;
char str[4000005];
long long int an=0;
long long int lastv=0;
long long int fl;

//long long int total;
void insert(char s[],long int no)
{
	long long int i=0;
	tr *cnt;
	cnt=a;
	while(s[i]!='\0')
	{
		if(a==NULL)
		{
			tr *temp=(tr*)malloc(sizeof(tr));
			temp->c=s[i];
			temp->sib=NULL;
			temp->ch=NULL;
			a=temp;
			cnt=a;
			a->e=0;
			a->ln=1;
			lastv=0;
		}
		else
		{
			while(cnt!=NULL)
			{
				if(cnt->c==s[i])
				{
					//if(s[i+1]=='\0')
					//	cnt->e=1;
					i++;
					if(cnt->ch!=NULL/*&&s[i+1]==cnt->ch->c*/)
						lastv=cnt->ch->ln+1;
					if(cnt->ch==NULL&&s[i]!='\0')
					{
						tr *t=(tr*)malloc(sizeof(tr));
						//printf("%c %ld",s[i],no-i);
						t->c=s[i];
						t->e=cnt->ln;
						t->sib=NULL;
						t->ch=NULL;
						//printf("%ld",lastv);
						if(i<=lastv+fl)
							t->ln=cnt->ln+1;
						else
							t->ln=no-lastv-i+1+no-i;
						/*
						if(cnt->ln+1<lastv+1+no-i)
							t->ln=cnt->ln+1;
						else
							t->ln=lastv+1+no-i;
						*/
						cnt->ch=t;
						//printf("%c %lld\n",t->c,t->ln);
						//if(s[i+1]=='\0')
						//	t->e=1;
						//i++;
					}
					cnt=cnt->ch;
				}
				else
				{
					if(cnt->sib==NULL&&s[i]!='\0')
					{
						tr *q=(tr*)malloc(sizeof(tr));
						q->c=s[i];
						//printf("%c %ld",s[i],no-i);
						q->e=cnt->e;
						q->sib=NULL;
						q->ch=NULL;
						if((no-i)%2==0)
							fl=(no-i+1)/2;
						else
							fl=(no-i)/2;
						q->ln=cnt->e+1;
						lastv=cnt->e+1;
						if(i==0)
							lastv=0;
						cnt->sib=q;
						//printf("%c %lld\n",q->c,q->ln);
						//if(s[i+1]=='\0')
						//	q->e=1;
						//i++;
					}
					cnt=cnt->sib;
				}
			}
		}
	}
	return;
}
void ans(char st[],long int no)
{
	long long int i;
	tr *j;
	j=a;
	i=0;
	while(st[i]!='\0')
	{
		if(j==NULL)
		{
			//printf("hi");
			an+=no-i+1;
			break;
		}
		else
		{
			if(j->c==st[i])
			{
				i++;
				//printf("%c %ld",j->c,j->ln);
				an=j->ln;
				j=j->ch;
			}
			else
			{
				//printf("%c",j->c);
				j=j->sib;
				//printf("lol");
			}
		}
	}
	return;
}
int main()
{
	long long int q=0,i=0,j=0;
	scanf("%lld%lld",&n,&q);
	for(i=0;i<n;i++)
	{
		lastv=0;
		scanf("%s",str);
		for(j=0;str[j]!='\0';j++);
		if(j%2==0)
			fl=j/2-1;
		else
			fl=j/2;
		insert(str,j-1);
	}
	//printf("%c %c",a->c,a->sib->c);
	for(i=0;i<q;i++)
	{
		an=0;
		scanf("%s",str);
		for(j=0;str[j]!='\0';j++);
			
		ans(str,j-1);

		printf("%lld\n",an);
		
		/*else
		{
			//and[i]=j;
			printf("%lld\n",j);
		}*/
	}
	//for(i=0;i<q;i++)
	//	printf("%lld \n",and[i]);
	return 0;
}




