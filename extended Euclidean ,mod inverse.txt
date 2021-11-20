ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	ll xx, yy;
	ll g = extended_euclid(b, a % b, xx, yy);
	x = yy;
	y = xx - yy * (a / b);
	return g;
}
ll mod_inverse(ll a, ll m)
{
	ll x, y;
	ll gc = extended_euclid(a, m, x, y);
	if (gc != 1) return -1;
	return (x % m + m) % m;
}
