int sz;
struct query
{
    int l,r,id;
    inline bool operator<(const query &t)const
    {
        return make_pair(l/sz,r)<make_pair(t.l/sz,t.r);
    }
} q[N];
int n,m,k;
ll v[N];
ll fr[2*N];
ll an=0;
ll ans[N];
void add(int i)
{
    an+=fr[v[i]^k];
    fr[v[i]]++;
}
void del(int i)
{
    fr[v[i]]--;
    an-=fr[v[i]^k];
}
void solve()
{
    cin>>n>>m>>k;
    fr(i,1,n)
    {
        cin>>v[i];
        v[i]^=v[i-1];
    }
    sz=sqrt(n);
    fr(i,0,m-1)
    {
        int l,r;
        cin>>q[i].l>>q[i].r;
        q[i].l--;
        q[i].id=i;
    }
    sort(q,q+m);
    int l=1,r=0;
    for(int i=0; i<m; i++)
    {
        query Q=q[i];
        while(Q.l<l)
            add(--l);
        while(Q.r>r)
            add(++r);
        while(Q.l>l)
            del(l++);
        while(Q.r<r)
            del(r--);
        ans[Q.id]=an;
    }
    fr(i,0,m-1)
    {
        cout<<ans[i]<<endl;
    }
}
