#include<stdio.h>
#include<stdlib.h>
typedef struct tr
{
	char c;
	struct tr *sib;
	struct tr *ch;
	long int lv;
	long int e;
}tr;
tr *a;
long int n;
char str[55];
long int an=0;
void insert(char s[])
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
			a->lv=-1;	
		}
		else
		{
			while(cnt!=NULL)
			{
				if(cnt->c==s[i])
				{
					if(s[i+1]=='\0')
					{
						cnt->e=cnt->e+1;
						//printf("%c",cnt->c);
					}
					i++;
					if(cnt->ch==NULL&&s[i]!='\0')
					{
						tr *t=(tr*)malloc(sizeof(tr));
						//printf("%c ",s[i]);
						t->c=s[i];
						t->e=0;
						t->sib=NULL;
						t->ch=NULL;
						t->lv=-1;
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
						//printf("%c ",s[i]);
						q->e=0;
						q->sib=NULL;
						q->ch=NULL;
						q->lv=-1;
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
/*
void ans(tr *t,char st[],long int i,int r,long int qn)
{
	tr *k;
	if(a==NULL) 
	{
		an=0;
		return;
	}
	else
	{
		if(st[i]=='\0')return;
		if(t==NULL)return;
		if(st[i]==t->c)
		{
			if(st[i+1]=='\0')
			{
				an+=t->e;
				t->lv=qn;
			//	printf("h");
			}
if((t->lv!=qn)&&((st[i+1]=='?'&&st[i+2]=='\0')||(st[i+1]=='?'&&st[i+2]=='?'&&st[i+3]=='\0')||(st[i+1]=='?'&&st[i+2]=='?'&&st[i+3]=='?'&&st[i+4]=='\0')))
			{
				an+=t->e;
				t->lv=qn;
			}
			i++;
			ans(t->ch,st,i,1,qn);
		}
		else if(st[i]=='?')
		{
			if(t->lv!=qn&&st[i+1]=='\0'&&t->ch!=NULL)
			{
				t->lv=qn;
				an+=t->e;
			}
			if(r==1)
				ans(t,st,i+1,1,qn);
			//ans(t->sib,st,i);
			//if(st[i+1]=='\0'&&st[i-1])
			//	an+=t->e;
			for(k=t;k!=NULL;k=k->sib)
			{
				//if(k->ch!=NULL)
				ans(k->ch,st,i+1,0,qn);
				if((t->lv!=qn)&&((st[i+1]=='\0')||(st[i+1]=='?'&&st[i+2]=='\0')||(st[i+1]=='?'&&st[i+2]=='?'&&st[i+3]=='\0')||(st[i+1]=='?'&&st[i+2]=='?'&&st[i+3]=='?'&&st[i+4]=='\0')))
				{
					k->lv=qn;
					an+=k->e;
				}

			}
			//for(k=t;k!=NULL;k=k->sib)
			//	ans(k,st,i+1);
		}
		else
			ans(t->sib,st,i,1,qn);
	}
}*/
/*void ans(tr *t,char st[],long int i)
{
	if(a==NULL) 
	{
		an=0;
		return;
	}
	else
	{
		if(st[i]=='\0')return;
		if(t==NULL)return;
		if(t->c==st[i]||st[i]=='?')
		{
			if(st[i+1]=='\0'&&t->e>=1)
				an+=t->e;
			if(st[i]=='?')
				ans(t->sib,st,i);
			i++;
			ans(t->ch,st,i);
		}
		else
			ans(t->sib,st,i);
	}
}*/
void ans(tr *t,char st[],long int i,long int qn)
{
	if(a==NULL)
	{
		an=0;
		return;
	}
	else
	{
		if(st[i]=='\0')return;
		if(t==NULL)return;
		if(st[i]==t->c)
		{
			if((t->lv!=qn)&&((st[i+1]=='\0')||(st[i+1]=='?'&&st[i+2]=='\0')||(st[i+1]=='?'&&st[i+2]=='?'&&st[i+3]=='\0')||(st[i+1]=='?'&&st[i+2]=='?'&&st[i+3]=='?'&&st[i+4]=='\0')))
			{
				t->lv=qn;
			//	printf("%c",t->c);
				an+=t->e;
				if(st[i+1]=='\0')
					return;
			}
			i++;
			ans(t->ch,st,i,qn);
		}
		else if(st[i]=='?')
		{
			if(st[i+1]=='\0'&&t->lv!=qn)
			{
				t->lv=qn;
				an+=t->e;
			}
			ans(t,st,i+1,qn);
			ans(t->sib,st,i,qn);
			ans(t->ch,st,i+1,qn);
		}
		else
			ans(t->sib,st,i,qn);
	}
}
int main()
{
	long int j=0,k=0;
	scanf("%ld",&n);
	for(j=0;j<n;j++)
	{
		scanf("%s",&str);
		insert(str);
	}
	//printf("%ld",a->e);
	scanf("%ld",&k);
	//printf("%c",a->ch->sib->c);
	for(j=0;j<k;j++)
	{
		an=0;
		scanf("%s",&str);
		ans(a,str,0,j);
		printf("%ld\n",an);
	}
	return 0;
}




					
				

