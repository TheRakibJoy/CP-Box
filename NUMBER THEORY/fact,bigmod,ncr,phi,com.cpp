ll fact[N+5];
void pre()
{
    fact[0]=1;
    fr(i,1,N)
    {
        fact[i]=i*fact[i-1];
        fact[i]%=MOD;
    }
}
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
ll ncr(ll n,ll r)
{
    if(n<r)
        return 0;
    ll an=1;
    an*=fact[n];
    ll d=fact[r];
    d*=fact[n-r];
    d%=MOD;
    an*=BigMod(d,MOD-2,MOD);
    an%=MOD;
    return an;
}
int phi[N+1];
void euler()
{
    for(int i=1; i<=N; i++)
        phi[i]=i;
    for(int i=2; i<=N; i++)
    {
        if(phi[i]==i)
        {
            for(ll j=i; j<=N; j+=i)
            {
                phi[j]-=(phi[j]/i);
            }
        }

    }
}
int Totient(int num)
{
	int ans = num;
	for(int i = 2; i * i <= num; i++)
	{
		if(num % i)
			continue;
		while(num % i == 0)
			num /= i;
		ans -= ans / i;
	}
	if(num > 1)
		ans -= ans / num;
	return ans;
}
ll com[1001][1001];
void combination()
{
    com[1][1]=1;
    com[0][0]=1;
    for(ll i=1; i<=1000; i++)
    {
        com[i][0]=1;
        for(ll j=1; j<=i; j++)
        {
            com[i][j]=com[i-1][j]+com[i-1][j-1];
            com[i][j]%=mod;
        }
    }
}
