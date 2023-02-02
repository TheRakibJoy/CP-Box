int dist(int u,int v)
{
    return lvl[u]+lvl[v]-2*lvl[get_LCA(u,v)];
}
//Decomposition Part
bool done[N];
int cenpar[N];
int sz[N];
int cur_subtree_size;
void set_subtree_size(int n,int p)
{
    sz[n]=1;
    cur_subtree_size++;
    for(auto it:adj[n])
    {
        if(it==p||done[it])
            continue;
        set_subtree_size(it,n);
        sz[n]+=sz[it];
    }
}
int get_centroid(int n,int p)
{
    for(auto it:adj[n])
    {
        if(it==p||done[it])
            continue;
        if(sz[it]>cur_subtree_size/2)
            return get_centroid(it,n);
    }
    return n;
}
void decompose(int n,int p)
{
    cur_subtree_size=0;
    set_subtree_size(n,p);
    int centroid=get_centroid(n,p);
    cenpar[centroid]=p;
    done[centroid]=1;
    for(auto it:adj[centroid])
    {
        if(it==p||done[it])
            continue;
        decompose(it,centroid);
    }
}
//query part
int ans[N];
void update(int n)
{
    int u=n;
    while(u)
    {
        ans[u]=min(ans[u],dist(u,n));
        u=cenpar[u];
    }
}
int query(int n)
{
    int u=n,an=1e9;
    while(u)
    {
        an=min(an,ans[u]+dist(n,u));
        u=cenpar[u];
    }
    return an;
}
//closest same colored nodes
//CF - 342 E
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    lvl[1]=0;
    dfs(1,0);
    Init_LCA(n);
    decompose(1,0);
    for(int i=1; i<=n; i++)
        ans[i]=1e7;
    update(1);
    for(int i=1; i<=m; i++)
    {
        int t,n;
        cin>>t>>n;
        if(t==1)
            update(n);
        else
            cout<<query(n)<<nl;
    }
}
