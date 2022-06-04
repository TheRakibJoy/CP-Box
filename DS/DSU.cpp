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
