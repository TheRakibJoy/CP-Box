struct DSU
{
    vector<int>par,sz,rnk;
    DSU(int n)
    {
        par.assign(n+1,0);
        rnk.assign(n+1,0);
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
            if(rnk[x]>rnk[y])
                swap(x,y);
            par[x]=y;
            if(rnk[x]==rnk[y])
                rnk[y]++;
            sz[y]+=sz[x];
            sz[x]=0;
        }
    }
    int get_size(int n)
    {
        return sz[get_parent(n)];
    }
};
