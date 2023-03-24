//starting with the name of almighty ALLAH
// Practice is the only shortcut to improve
//https://www.spoj.com/problems/COT2/
//Unique numbers in a path
#include<bits/stdc++.h>
#define ll long long int
#define rj ios::sync_with_stdio(false);cin.tie(0);
#define nl '\n'
const int N = 4e4 + 2, CN = 3e5 + 2;//CN- Highest Time
using namespace std;
int v[N];
vector<int>adj[N];
int par[N][20], lvl[N];
int T;
int in[N], out[N], nd[CN];
void dfs(int n, int p = 0)
{
	par[n][0] = p;
	lvl[n] = lvl[p] + 1;
	in[n] = ++T;
	nd[T] = n;
	for (int k = 1; k < 20; k++)
		par[n][k] = par[par[n][k - 1]][k - 1];
	for (auto it : adj[n])
		if (it != p) dfs(it, n);
	out[n] = ++T;
	nd[T] = n;
}
int lca(int u, int v)
{
	if (lvl[u] < lvl[v]) swap(u, v);
	for (int k = 19; k >= 0; k--)
		if (lvl[par[u][k]] >= lvl[v]) u = par[u][k];
	if (u == v) return u;
	for (int k = 19; k >= 0; k--)
		if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
	return par[u][0];
}
int sz = 320;
struct query
{
	int l, r, id;
	inline bool operator<(const query &t) const
	{
		return make_pair(l / sz, r) < make_pair(t.l / sz, t.r);
	}
} Q[100002];
int mp[N], frq[N], an, ans[100002];
void go(int i)
{
	if (i == 0)  return;
	mp[i] ^= 1;
	if (mp[i] == 0)
	{
		frq[v[i]]--;
		if (frq[v[i]] == 0) an--;
		return;
	}
	frq[v[i]]++;
	if (frq[v[i]] == 1) an++;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	map<int, int>com;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		com[v[i]];
	}
	int cnt = 0;
	for (auto &it : com)
		it.second = cnt++;
	for (int i = 1; i <= n; i++)
	{
		v[i] = com[v[i]];
	}
	for (int i = 2; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	T = 0;
	dfs(1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (in[u] > in[v]) swap(u, v);
		int lc = lca(u, v);
		if (lc == u)
		{
			Q[i].l = in[u], Q[i].r = in[v], Q[i].id = i;
		}
		else
		{
			Q[i].l = out[u], Q[i].r = in[v], Q[i].id = i;
		}
	}
	sz = sqrtl(T);
	sort(Q, Q + m);
	int l = 1, r = 0;
	for (int i = 0; i < m; i++)
	{
		while (Q[i].l < l)
			go(nd[--l]);
		while (Q[i].r > r)
			go(nd[++r]);
		while (Q[i].l > l)
			go(nd[l++]);
		while (Q[i].r < r)
			go(nd[r--]);
		int lc = lca(nd[Q[i].l], nd[Q[i].r]);
		if (lc != nd[Q[i].l]) go(lc);//LCA CASE
		ans[Q[i].id] = an;
		if (lc != nd[Q[i].l]) go(lc);
	}
	for (int i = 0; i < m; i++) cout << ans[i] << '\n';

}
int main()
{
	rj
	solve();
	return 0;
}
