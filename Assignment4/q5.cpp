#include<bits/stdc++.h>
using namespace std;

long long int n;
int st[100005];
vector<long long int> ptr[100005];
long long int max0,max1;
int vi0[100005],vi1[100005];

long long int dfs(vector<long long int> u,long long int curr,long long int p,int op)
{
    long long int i,val=0,ch;
    /*if(u.size()==0)
    {
        if(op==0)
        {
            
            vi0[curr]=1;
            if(st[curr]==1)
                return -1;
            else
            {
                if(max0<1)
                    max0=1;
                return 1;
            }    
        }
        else
        {
            vi1[curr]=1;
            if(st[curr]==0)
               return -1;
            else
            {
                if(max1<1)
                    max1=1;
                return 1;    
            }    
            
        }
    }
    else*/
    //{
        for(i=0;i<u.size();i++)
        {
            if(op==0)
            {
                if(vi0[u[i]]==0&&u[i]!=p)
                {
                    vi0[u[i]]=1;
                    ch=dfs(ptr[u[i]],u[i],curr,op);
                    if(ch>0)
                        val+=ch;    
                }
            }
            else
            {
                if(vi1[u[i]]==0&&u[i]!=p)
                {
                    vi1[u[i]]=1;
                    ch=dfs(ptr[u[i]],u[i],curr,op);
                    if(ch>0)
                        val+=ch;        
                }
            }
        }
        if(op==0)
        {
            if(st[curr]==0)
                val+=1;
            else
                val-=1;
            if(max0<val)
                max0=val;            
        }
        else
        {
            if(st[curr]==1)
                val+=1;
            else
                val-=1;
            if(max1<val)
                max1=val;            
        }
        //cout<<curr<<" "<<max0<<"\n ";
        return val;
    }
}

int main()
{
    long long int i,a,b;
    max0=0;max1=0;
    cin>>n;
    for(i=1;i<=n;i++)
       cin>>st[i];

       //rohan found a bug for n=1
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        ptr[a].push_back(b);
        ptr[b].push_back(a);
    }
    dfs(ptr[a],a,-1,0);
    dfs(ptr[a],a,-1,1);
    if(max0<max1)
        cout<<max1;
    else
        cout<<max0;    
    return 0;
}