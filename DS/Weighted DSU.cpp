//Helps to maintain val[x]-val[y]=d for some a,b
struct DSU
{
	vector<ll>par, sz, rnk, sum;
	DSU(int n)
	{
		par.assign(n + 1, 0);
		rnk.assign(n + 1, 0);
		sum.assign(n + 1, 0);
		sz.assign(n + 1, 1);
		for (int i = 1; i <= n; i++)
			par[i] = i;
	}
	int get_parent(int n)
	{
		if (par[n] == n)
			return n;
		ll t = get_parent(par[n]);
		sum[n] += sum[par[n]];
		par[n] = t;
		return par[n];
	}
	void union_set(int x, int y, int d)
	{
		//maintains val[x]-val[y]=d
		int px = x, py = y;
		x = get_parent(x);
		y = get_parent(y);
		if (x != y)
		{
			if (rnk[x] > rnk[y])
				swap(x, y), swap(px, py), d = -d;
			par[x] = y;
			if (rnk[x] == rnk[y])
				rnk[y]++;
			sum[x] = sum[py] - sum[px] + d;
			sz[y] += sz[x];
			sz[x] = 0;
		}
	}
	int get_size(int n)
	{
		return sz[get_parent(n)];
	}
};
