#include<iostream>
#include<list>
using namespace std;
struct T
{
	long int p;
	long int w;
};
typedef struct T T;
typedef list<T>::iterator li;
list<T> a[10005];
void push(T b,T c)
{
	a[b.p].push_back(c);
	a[c.p].push_back(b);
}
/*merge(li s,li e)
{
	list<T> t1[50005],t2[50005];
	li i,j,k;
	*/
int main()
{
	long int n,i,k;
	T b,c;
	cin>>n;
	k=n;
	for(i=0;i<n;i++)
	{
		cin>>b.p>>c.p>>b.w;
		c.w=b.w;
		push(b,c);
	}
	li t=a[1].begin();
	li r=a[1].end();
	li m=*((*t)+(*r))/2;
	return 0;
}



