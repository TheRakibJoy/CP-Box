int v[N];
struct Stree
{
#define lf (nd << 1)
#define rt ((nd << 1) | 1)
    long long t[4 * N], lazy[4 * N];
    Stree()
    {
    }
    inline void push(int nd, int lo, int hi)
    {
        if (lazy[nd] == 0)
            return;
        t[nd] = t[nd] + lazy[nd] * (hi - lo + 1);
        if (lo != hi)
        {
            lazy[lf] = lazy[lf] + lazy[nd];
            lazy[rt] = lazy[rt] + lazy[nd];
        }
        lazy[nd] = 0;
    }
    inline long long milao(long long x,long long y)
    {
        return x + y;
    }
    inline void uthao(int nd)
    {
        t[nd] = t[lf] + t[rt];
    }
    void build(int nd, int lo, int hi)
    {
        lazy[nd] = 0;
        if (lo == hi)
        {
            t[nd] = v[lo];
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
    long long query(int nd, int lo, int hi, int i, int j)
    {
        push(nd, lo, hi);
        if (i > hi || lo > j)
            return 0;
        if (i <= lo && hi <= j)
            return t[nd];
        int mid = (lo + hi) >> 1;
        return milao(query(lf, lo, mid, i, j), query(rt, mid + 1, hi, i, j));
    }
};
