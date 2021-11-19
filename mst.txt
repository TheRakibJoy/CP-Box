struct edge
{
    int u, v, w;
    bool operator<(const edge& cm) const
    {
        return w < cm.w;
    }
};
vector<edge> e;
ll par[N+5];
void init(ll n)
{
    fr(i,1,n) par[i]=i;
}
ll get(ll n)
{
    if(par[n]==n)
        return n;
    return par[n]=get(par[n]);
}
void uni(ll a,ll b)
{
    par[a]=b;
}
ll mst(int n)
{
    sort(e.begin(), e.end());
    init(n);
    ll cnt = 0, s = 0;
    for (int i = 0; i < (int)e.size(); i++)
    {
        int u = get(e[i].u);
        int v = get(e[i].v);
        if (u != v)
        {
            uni(u,v);
            cnt++;
            s += (ll)e[i].w;
            if (cnt == n - 1)
                break;
        }
    }
    return s;
}
