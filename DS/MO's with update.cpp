//Problem - https://toph.co/p/distinct-dishting
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
int sz;
const int N=1e5+1;
struct query
{
    int l,r,id,t;
    inline bool operator<(const query &o)const
    {
        if(l/sz!=o.l/sz)
            return l<o.l;
        if(r/sz!=o.r/sz)
            return r<o.r;
        return t<o.t;
    }
} q[N];
struct updt
{
    int i,nxt,prv;
} u[N];
int v[N],L=1,R=0,T=-1;
gp_hash_table<int,int>m;
long long an=0,ans[N];
void add(int i)
{
    int x=v[i];
    if(x%3) return;
    m[x]++;
    if(m[x]==1) an+=x;
}
void del(int i)
{
    int x=v[i];
    if(x%3) return;
    m[x]--;
    if(m[x]==0) an-=x;
}
void updo(int i)
{
    int j=u[i].i,nxt=u[i].nxt;
    if(j>=L and j<=R)
        del(j);
    v[j]=nxt;
    if(j>=L and j<=R)
        add(j);
}
void undo(int i)
{
    int j=u[i].i,prv=u[i].prv;
    if(j>=L and j<=R)
        del(j);
    v[j]=prv;
    if(j>=L and j<=R)
        add(j);
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0; i<a; i++)
        scanf("%d",&v[i]);
    int uc=-1,qc=0;
    for(int i=0; i<b; i++)
    {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(t==0)
        {
            x--;
            uc++;
            u[uc]= {x,y,v[x]};
            v[x]=y;
        }
        else
        {
            x--,y--;
            q[qc]= {x,y,qc,uc},qc++;
        }
    }
    sz=2*powl(a,0.666666666667);
    sort(q,q+qc);
    T=uc;
    for(int i=0; i<qc; i++)
    {
        int l=q[i].l,r=q[i].r,qt=q[i].t;
        while(T<qt)
            updo(++T);
        while(T>qt)
            undo(T--);
        while(l<L)
            add(--L);
        while(r>R)
            add(++R);
        while(l>L)
            del(L++);
        while(r<R)
            del(R--);
        ans[q[i].id]=an;
    }
    for(int i=0;i<qc; i++)
    {
        printf("%lld\n",ans[i]);
    }
    return 0;
}
