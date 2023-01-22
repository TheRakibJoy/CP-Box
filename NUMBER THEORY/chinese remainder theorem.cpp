using T=__int128;//__int128 usable
// ax + by = __gcd(a, b)
// returns __gcd(a, b)
T extended_euclid(T a, T b, T &x, T &y)
{
    T xx = y = 0;
    T yy = x = 1;
    while (b)
    {
        T q = a / b;
        T t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}
// finds x such that x % m1 = a1, x % m2 = a2.
// m1 and m2 may not be coprime
// here, x is unique modulo m = lcm(m1, m2).
// returns (x, m). on failure, m = -1.
pair<ll, T> CRT( vector<ll> A, vector<ll> M )
{
    if(A.size() != M.size())
        return {0,-1}; /** Invalid input*/

    int n = A.size();

    T a1 = A[0];
    T m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/

    /** Merge the solution with remaining equations */
    for ( int i = 1; i < n; i++ )
    {
        T a2 = A[i];
        T m2 = M[i];
        T p, q;
        T g = extended_euclid(m1, m2, p, q);
        if (a1 % g != a2 % g)
            return make_pair(0, -1);
        T m = m1 / g * m2;
        p = (p % m + m) % m;
        q = (q % m + m) % m;
        T x=(p * a2 % m * (m1 / g) % m + q * a1 % m * (m2 / g) % m) %  m;
        a1=x;
        m1=m;
    }
    return {a1, m1};
}
