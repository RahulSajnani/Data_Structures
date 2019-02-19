#include<stdio.h>
#include<stdlib.h>
typedef struct tr
{
	char c;
	struct tr *sib;
	struct tr *ch;
	long int ln;
	long int e;
}tr;
tr *a;
long int n;
char str[4000005];
long int an=0;
long int lastv;
int fl;
long int total;
void insert(char s[],long int no)
{
	int i=0;
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
			a->ln=no-i;	
		}
		else
		{
			while(cnt!=NULL)
			{
				if(cnt->c==s[i])
				{
					if(s[i+1]=='\0')
						cnt->e=1;
					i++;
					if(cnt->ch==NULL&&s[i]!='\0')
					{
						tr *t=(tr*)malloc(sizeof(tr));
						//printf("%c %ld",s[i],no-i);
						t->c=s[i];
						t->e=0;
						t->sib=NULL;
						t->ch=NULL;
						t->ln=no-i;
						cnt->ch=t;
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
						q->e=0;
						q->sib=NULL;
						q->ch=NULL;
						q->ln=no-i;
						cnt->sib=q;
						//if(s[i+1]=='\0')
						//	q->e=1;
						//i++;
					}
					cnt=cnt->sib;
				}
			}
		}
	}
}
void ans(tr *t,char st[],long int i,long int no)
{
	if(st[i]=='\0')
		return;
	if(total>no+1)
	{
		total=no;
		return;
	}
	if(t==NULL)
	{
		if(st[i]!='\0')
			total+=no-i;
		if(total>no)
			total=no;
		return;
		/*if((an+no-i)<no)
			an=an+no-i;
		else
			an=no+1;
		return;*/
	}
	if(i==0)
	{
		if(t->c==st[i])
		{
			if(st[1]=='\0')
				total=1;
			lastv=1;
			fl=0;
			ans(t->ch,st,i+1,no);
		}
		else if(t->sib==NULL)
			total=no;
		else
			ans(t->sib,st,i,no);
	}
	else
	{
		if(t->c==st[i])
		{
			if(lastv!=i+1)
			{
				if(i-lastv+1<2+t->ln)
					an=i+1-lastv;
				else
					an=2+t->ln;
			}
			/*if(i+1<lastv+1+t->lv);
				an=i+1;
			else
				an=lastv+1+t->lv;
			lastv=i+1;*/
			if(t->e==1)
			{
				if(i+1-lastv>2)
					total+=2;
				else
					total+=i+1-lastv;
				lastv=i+1;
				an=0;
			}
			if(st[i+1]=='\0')
				total+=an;
			fl=0;
			ans(t->ch,st,i+1,no);
		}
		else
		{
			if(fl==0)
			{
				an+=1;
				fl=1;
				total+=an;
				an=0;
				lastv=i+1;
			}
			ans(t->sib,st,i,no);
		}
	}
}
int main()
{
	long int i,j,q;
	scanf("%ld %ld",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%s",&str);
		for(j=0;str[j]!='\0';j++);
		insert(str,j-1);
	}
	for(i=0;i<q;i++)
	{
		total=0;
		scanf("%s",&str);
		for(j=0;str[j]!='\0';j++);
		ans(a,str,0,j);
		printf("%ld\n",total);
	}
	//printf("%c %ld %c %ld",a->c,a->ln,a->ch->c,a->ch->ln);
	return 0;
}




