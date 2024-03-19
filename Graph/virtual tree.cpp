const int B = 20;
int par[N][B], lvl[N], st[N], en[N];
vector<int>adj[N];
int T;
void dfs(int n, int p = 0)
{
	st[n] = ++T;
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
	en[n] = T;
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

int isanc(int u, int v) {
	return (st[u] <= st[v]) && (en[v] <= en[u]);
}
vector<int> t[N];
// given specific nodes, construct a compressed directed tree with these vertices(if needed some other nodes included)
// returns the nodes of the tree
// nodes.front() is the root
// t[] is the specific tree
vector<int> buildtree(vector<int> v) {
	// sort by entry time
	sort(v.begin(), v.end(), [](int x, int y) {
		return st[x] < st[y];
	});
	// finding all the ancestors, there are few of them
	int s = v.size();
	for (int i = 0; i < s - 1; i++) {
		int lc = get_LCA(v[i], v[i + 1]);
		v.push_back(lc);
	}
	// removing duplicated nodes
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	// again sort by entry time
	sort(v.begin(), v.end(), [](int x, int y) {
		return st[x] < st[y];
	});
	stack<int> st;
	st.push(v[0]);
	for (int i = 1; i < v.size(); i++) {
		while (!isanc(st.top(), v[i])) st.pop();
		t[st.top()].push_back(v[i]);
		st.push(v[i]);
	}
	return v;
}
