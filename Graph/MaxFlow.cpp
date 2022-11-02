///Template from great Bappy Vai
const int sz = 105;
struct Edge
{
    int u,v,cap;
    Edge() {}
    Edge(int uu,int vv,int _cap)
    {
        u = uu;
        v = vv;
        cap = _cap;
    }
};
vector<Edge>edge;
vector<int>edgeno[sz];
bool vis[sz];
int src,sink;
void AddEdge(int u,int v,int w)
{
    edge.push_back(Edge(u, v, w));
    edge.push_back(Edge(v, u, 0));///As it's an unidirectional edge

    edgeno[u].push_back(edge.size() - 2);  ///Even indexed
    edgeno[v].push_back(edge.size() - 1);  ///Odd indexed
}
int DFS(int u,int flow=1e9)
{
    vis[u] = 1;
    if(u == sink)
        return flow;
    int an = 0;
    for(int i=0 ; i<(int)edgeno[u].size() ; i++)
    {
        int id = edgeno[u][i];
        Edge &cr = edge[id];

        if(!cr.cap || vis[cr.v])
            continue;

        an = DFS(cr.v, min(flow, cr.cap));

        if(an)
        {
            Edge &rev = edge[id ^ 1];  ///Every forward edge stored in even index & every backward edge stored in next odd index
            cr.cap -= an;
            rev.cap += an;
            return an;
        }
    }
    return an;
}
int FordFulkerson()
{
    int MaxFlow=0;
    while(1)
    {
        memset(vis, 0, sizeof(vis));
        int possible = DFS(src);
        if(possible == 0)
            break;
        MaxFlow += possible;
    }
    return MaxFlow;
}
