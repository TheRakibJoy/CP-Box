struct Stree
{
#define lf (nd << 1)
#define rt ((nd << 1) | 1)
	int t[4 * N], lazy[4 * N];
	Stree()
	{
	}
	inline void push(int nd, int lo, int hi)
	{
		if (lazy[nd] == 0)
			return;
		t[nd] = t[nd] + lazy[nd];
		if (lo != hi)
		{
			lazy[lf] = lazy[lf] + lazy[nd];
			lazy[rt] = lazy[rt] + lazy[nd];
		}
		lazy[nd] = 0;
	}
	inline long long milao(long long x, long long y)
	{
		return max(x , y);
	}
	inline void uthao(int nd)
	{
		t[nd] = max(t[lf] , t[rt]);
	}
	void build(int nd, int lo, int hi)
	{
		lazy[nd] = 0;
		if (lo == hi)
		{
			t[nd] = 0;
			return;
		}
		int mid = (lo + hi) >> 1;
		build(lf, lo, mid);
		build(rt, mid + 1, hi);
		uthao(nd);
	}
	void update(int nd, int lo, int hi, int i, int j, long long val)
	{
		push(nd, lo, hi);
		if (j < lo || hi < i)
			return;
		if (i <= lo && hi <= j)
		{
			lazy[nd] = val; //set lazy
			push(nd, lo, hi);
			return;
		}
		int mid = (lo + hi) >> 1;
		update(lf, lo, mid, i, j, val);
		update(rt, mid + 1, hi, i, j, val);
		uthao(nd);
	}
	int query(int nd, int lo, int hi, int i, int j)
	{
		push(nd, lo, hi);
		if (i > hi || lo > j)
			return -1e9;
		if (i <= lo && hi <= j)
			return t[nd];
		int mid = (lo + hi) >> 1;
		return milao(query(lf, lo, mid, i, j), query(rt, mid + 1, hi, i, j));
	}
} t;
vector<int>adj[N];
const int B = 20;
int par[N][B], lvl[N], sz[N];
void dfs(int n, int p = 0)
{
	par[n][0] = p;
	lvl[n] = lvl[p] + 1;
	for (int i = 1; i < B; i++)
		par[n][i] = par[par[n][i - 1]][i - 1];
	sz[n] = 1;
	for (auto &it : adj[n])
	{
		if (it != p)
		{
			dfs(it, n);
			sz[n] += sz[it];
			if (sz[it] > sz[adj[n][0]])
				swap(it, adj[n][0]);
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
	int p = n;
	for (int i = 0; i <= B; i++)
	{
		if (k & (1 << i))
			p = par[p][i];
	}
	return p;
}
int T, head[N], st[N], en[N];
void dfs_hld(int n, int p = 0)
{
	st[n] = ++T;
	for (auto it : adj[n])
	{
		if (it != p)
		{
			head[it] = (it == adj[n][0] ? head[n] : it);
			dfs_hld(it, n);
		}
	}
	en[n] = T;
}
int a;
int go_up(int u, int v) //path u->v
{
	int ans = -1e9;
	while (head[u] != head[v])
	{
		ans = max(ans, t.query(1, 1, a, st[head[u]], st[u]));
		u = par[head[u]][0];
	}
	ans = max(ans, t.query(1, 1, a, st[v], st[u]));
	return ans;
}
int query(int u, int v)
{
	int l = get_LCA(u, v);
	int ans = go_up(u, l);
	if (v != l)
		ans = max(ans, query(v, get_kth(v, lvl[v] - lvl[l] - 1)));
	return ans;
}
void solve()
{
	cin >> a;
	for (int i = 1; i < a; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1);
	head[1] = 1;
	dfs_hld(1);
	t.build(1, 1, a);
	int q;
	cin >> q;
	while (q--)
	{
		string ty;
		int x, y;
		cin >> ty >> x >> y;
		if (ty == "add")
		{
			t.update(1, 1, a, st[x], en[x], y);
		}
		else
		{
			cout << query(x, y) << nl;
		}
	}
}
//https://www.hackerrank.com/challenges/subtrees-and-paths/problem
