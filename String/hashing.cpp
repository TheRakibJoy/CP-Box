int BigMod(long long p, long long q, const int mod)
{
    int ans = 1 % mod;
    p %= mod;
    if (p < 0)
        p += mod;
    while (q)
    {
        if (q & 1)
            ans = (long long) ans * p % mod;
        p = (long long) p * p % mod;
        q >>= 1;
    }
    return ans;
}

const int MOD1 = 127657753, MOD2 = 987654319;
const int b1 = 141, b2 = 277;
int inp1, inp2;
pair<int, int> pw[N], inpw[N];
//Template from YouKnow
void precalc()
{
    pw[0] =  {1, 1};
    for (int i = 1; i < N; i++)
    {
        pw[i].first = 1LL * pw[i - 1].first * b1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * b2 % MOD2;
    }
    inp2 = BigMod(b2, MOD2 - 2, MOD2);
    inp1 = BigMod(b1, MOD1 - 2, MOD1);
    inpw[0] =  {1, 1};
    for (int i = 1; i < N; i++)
    {
        inpw[i].first = 1LL * inpw[i - 1].first * inp1 % MOD1;
        inpw[i].second = 1LL * inpw[i - 1].second * inp2 % MOD2;
    }

}
struct Hashing
{
    int sz;
    string s; // 0 - indexed string
    vector<pair<int, int>> h_tab; // 1 - indexed vector
    Hashing() {}
    Hashing(string _ss)
    {
        sz = _ss.size();
        s = _ss;
        h_tab.emplace_back(0, 0);
        for (int i = 0; i < sz; i++)
        {
            pair<int, int> p;
            p.first = (h_tab[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (h_tab[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
            h_tab.push_back(p);
        }
    }
    pair<int, int> get_hash_value(int lo, int hi)   // 1 - indexed
    {
        assert(1 <= lo && lo <= hi && hi <= sz);
        pair<int, int> ans;
        ans.first = (h_tab[hi].first - h_tab[lo - 1].first + MOD1) * 1LL * inpw[lo - 1].first % MOD1;
        ans.second = (h_tab[hi].second - h_tab[lo - 1].second + MOD2) * 1LL * inpw[lo - 1].second % MOD2;
        return ans;
    }
    pair<int, int> get_hash_value()
    {
        return get_hash_value(1, sz);
    }
};
pair<int, int> mer(pii x, pii y, int z)//z-len of x
{
    pii an;
    an.F = (x.F + (1LL * pw[z].F * y.F) % MOD1) % MOD1;
    an.S = (x.S + (1LL * pw[z].S * y.S) % MOD2) % MOD2;
    return an;
}
