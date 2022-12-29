//Persistent Segment Tree
struct node
{
    node *lf, *rt;
    int val;
    node(int x = 0, node *y = NULL, node *z = NULL) :
        val(x), lf(y), rt(z) {}

    void build(int lo, int hi)
    {
        if(lo == hi)
            return;
        lf = new node();
        rt = new node();
        int mid = lo + hi >> 1;
        lf -> build(lo, mid);
        rt -> build(mid+1, hi);
    }
    node *update(int lo, int hi, int idx, int v)
    {
        if(hi < idx || lo > idx)
            return this;
        if(lo == hi)
        {
            node *ret = new node(val, lf, rt);
            ret -> val += v;
            return ret;
        }
        int mid = lo + hi >> 1;
        node *ret = new node(val);
        ret -> lf = lf -> update(lo, mid, idx, v);
        ret -> rt = rt -> update(mid+1, hi, idx, v);
        ret -> val = ret -> lf -> val + ret -> rt -> val;
        return ret;
    }
    int query(int lo, int hi, int i, int j)
    {
        if(hi < i || lo > j)
            return 0;
        if(i <= lo && hi <= j)
        {
            return val;
        }
        int mid = lo + hi >> 1;
        return lf -> query(lo, mid,i,j) +
               rt -> query(mid+1, hi,i,j);
    }
}*root[N];
// in main()
root[0] = new node();
root[0] -> build(0, n-1);
root[1] = root[0] -> update(0, n-1, idx, v);
// So, we're gonna update idx position in root[0]'s segment tree
// and it will return a pointer to the root of new segment tree.
// We store that pointer in root[1] for later use.

// If we want to update in a perticular version,
// but not create new version then -
root[0] = root[0] -> update(0, n-1, idx, v);
// We again store the new version's root in the same position or root[] array!
