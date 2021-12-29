int v[N];
struct Stree
{
#define lf (nd << 1)
#define rt ((nd << 1) | 1)
    int t[4 * N];
    static const int inf = -1e9;
    Stree()
    {
        memset(t, 0, sizeof t);
    }
    void build(int nd, int lo, int hi)
    {
        if (lo == hi)
        {
            t[nd] = v[lo];
            return;
        }
        int mid = (lo + hi) >> 1;
        build(lf, lo, mid);
        build(rt, mid + 1, hi);
        t[nd] = max(t[lf], t[rt]);
    }
    void update(int nd, int lo, int hi, int i, int x)
    {
        if (lo > i || hi < i)
            return;
        if (lo == hi && lo == i)
        {
            t[nd] = x;
            return;
        }
        int mid = (lo + hi) >> 1;
        update(lf, lo, mid, i, x);
        update(rt, mid + 1, hi, i, x);
        t[nd] = max(t[lf], t[rt]);
    }
    int query(int nd, int lo, int hi, int i, int j)
    {
        if (lo > j || hi < i)
            return inf;
        if (lo >= i && hi <= j)
            return t[nd];
        int mid = (lo + hi) >> 1;
        int L = query(lf, lo, mid, i, j);
        int R = query(rt, mid + 1, hi, i, j);
        return max(L, R);
    }
};
