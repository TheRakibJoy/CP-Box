using T= long long;// __int128 may needed
// ax + by = __gcd(a, b)
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
/** Return {-1,-1} if invalid input.
    Otherwise, returns {x,L}, where x is the solution unique to mod L
*/
pair<T, T> CRT( vector<T> A, vector<T> M )
{
    if(A.size() != M.size())
        return {-1,-1}; /** Invalid input*/

    T n = A.size();

    T a1 = A[0];
    T m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/

    /** Merge the solution with remaining equations */
    for ( T i = 1; i < n; i++ )
    {
        T a2 = A[i];
        T m2 = M[i];

        /** Merge the two equations*/
        T p, q;
        extended_euclid(m1, m2, p, q);

        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        T x = (a1*m2*q + a2*m1*p) % (m1*m2);

        /** Merged equation*/
        a1 = x;
        m1 = m1 * m2;
    }
    if (a1 < 0)
        a1 += m1; /** Result is not suppose to be negative*/
    return {a1, m1};
}
