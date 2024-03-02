const int B = 20;
int par[N][B], lvl[N];
vector<int>adj[N];
void dfs(int n, int p = 0)
{
	par[n][0] = p;
	lvl[n] = lvl[p] + 1;
	for (int i = 1; i < B; i++)
	{
		par[n][i] = par[par[n][i - 1]][i - 1];
	}
	for (auto it : adj[n])
	{
		if (it != p)
		{
			dfs(it, n);
		}
	}
}
int get_LCA(int p, int q)
{
	if (lvl[p] < lvl[q])
		swap(p, q);
	int Log = log2(lvl[p]) + 1;
	for (int i = Log ; i >= 0 ; i--)
	{
		if (lvl[p] - (1 << i) >= lvl[q])
			p = par[p][i];
	}
	if (p == q)
		return p;
	for (int i = Log ; i >= 0 ; i--)
	{
		if (par[p][i] != par[q][i])
		{
			p = par[p][i];
			q = par[q][i];
		}
	}
	return par[p][0];
}
int get_kth(int n, int k)
{
	int Log = log2(k);
	int p = n;
	for (int i = 0; i <= Log; i++)
	{
		if (k & (1 << i))
			p = par[p][i];
	}
	return p;
}
