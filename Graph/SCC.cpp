bool vis[N+5];
vector<int>component,topsort;
vector<int>g[N+5],rg[N+5];
void dfs(int n)
{
    vis[n]=1;
    for(auto it:g[n])
    {
        if(!vis[it])
            dfs(it);
    }
    topsort.push_back(n);
}
void dfs2(int n)
{
    component.push_back(n);
    vis[n]=1;
    for(auto it:rg[n])
    {
        if(!vis[it])
            dfs2(it);
    }
}
//g- graph ,rg- reversed graph
//After calling dfs topsort should be reversed
//The you have to call in topological order
//After each call component vector should be cleared
