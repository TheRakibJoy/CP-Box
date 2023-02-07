//get k-th fibonacci number where first and second fibonacci is a and b
ll get_kth(ll a,ll b,ll k)
{
    a%=MOD;
    b%=MOD;
    if(k==1)
        return a;
    if(k==2)
        return b;
    return ((a*f[k-2])%MOD+(b*f[k-1])%MOD)%MOD;
}
//sum of fib[1]+fib[2]+...+fib[len]=fib[len+2]-fib[2];
