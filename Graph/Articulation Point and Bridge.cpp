//For multiple test case, Never forget to clear these things
int T, low[N], dis[N], art[N];
vector<int> adj[N];
void dfsArt(int u, int par = 0) {
	low[u] = dis[u] = ++T;
	int child = 0;
	for (auto v : adj[u]) {
		if (!dis[v]) {
			dfsArt(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dis[u] && par != 0)
			{
				//For bridge, remove equal sign and par!=0 condition
				//Then just store (u,v) in a DS
				
				art[u] = 1;
			}
			++child;
		}
		else if (v != par) low[u] = min(low[u], dis[v]);
	}
	if (par == 0 && child > 1) art[u] = 1;
}
void Articulation(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (!dis[i])
			dfsArt(i);
	}
}
