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
long long int li;
int br;
void insert(char s[],long long int no)
{
	tr *cnt;
	long long int i=0;
	cnt=a;
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
		br=1;
		li=-1;
		//i++;
	}
	while(cnt!=NULL)
	{
		if(cnt->c==str[i])
		{
			i++;
			if(cnt->ch==NULL&&str[i]!='\0')
			{
				if(br==0)
				{
					lastv=cnt->ln;
					br=1;
					li=i-1;
					if((no-i+1)%2==0)	
						fl=(no-i+1)/2;
					else
						fl=(no-i+1)/2+1;
				}
				tr *t=(tr*)malloc(sizeof(tr));
				t->c=s[i];
				t->sib=NULL;
				t->ch=NULL;
				t->e=cnt->ln;
				if(i<=li+fl)
					t->ln=cnt->ln+1;
				else
					t->ln=lastv+2+no-i;
				if(i+1<t->ln)
					t->ln=i+1;
				cnt->ch=t;
			//	printf("%c %lld",t->c,t->ln);
			}
			cnt=cnt->ch;
		}
		else
		{
			if(i!=0)
				lastv=cnt->e;
			if(cnt->sib==NULL&&s[i]!='\0')
			{
				tr *t1=(tr*)malloc(sizeof(tr));
				t1->c=s[i];
				t1->sib=NULL;
				t1->ch=NULL;
				if((no-i+1)%2==0)
					fl=(no-i+1)/2;
				else
					fl=(no-i+1)/2+1;
				t1->e=cnt->e;
				t1->ln=cnt->e+1;
				cnt->sib=t1;
				li=i-1;
			//	printf("%c %lld",t1->c,t1->ln);
				br=1;
			}
			cnt=cnt->sib;
		}
	}
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
		br=0;
		lastv=0;
		scanf("%s",str);
		for(j=0;str[j]!='\0';j++);
		if(j%2==0)
			fl=j/2;
		else
			fl=j/2+1;
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




