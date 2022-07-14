struct DSU
{
    vector<int>par,sz;
    DSU(int n)
    {
        par.assign(n+1,0);
        sz.assign(n+1,1);
        for(int i=1; i<=n; i++)
            par[i]=i;
    }
    int get_parent(int n)
    {
        if(par[n]==n)
            return n;
        return par[n]=get_parent(par[n]);
    }
    void union_set(int x,int y)
    {
        x=get_parent(x);
        y=get_parent(y);
        if(x!=y)
        {
            if(sz[x]<sz[y])
                swap(x,y);
            par[y]=x;
            sz[x]+=sz[y];
            sz[y]=0;
        }
    }
    int get_size(int n)
    {
        return sz[get_parent(n)];
    }
};
struct edge
{
    int u, v, w;
    bool operator<(const edge& cm) const
    {
        return w < cm.w;
    }
};
vector<edge> e;
ll mst(int n)
{
    sort(e.begin(), e.end());
    DSU d(n);
    ll cnt = 0, s = 0;
    for (int i = 0; i < (int)e.size(); i++)
    {
        int u=e[i].u,v=e[i].v;
        if (d.get_parent(u) != d.get_parent(v))
        {
            d.union_set(u,v);
            cnt++;
            s += (ll)e[i].w;
            if (cnt == n - 1)
                break;
        }
    }
    return s;
}
