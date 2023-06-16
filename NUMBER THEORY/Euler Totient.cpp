/*Notes-
x+y==n and gcd(x,y)==1, number of pairs (x,y)=phi(n)
Sum of Phi(n/d) ,where d is a divisor is = n
*/	
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
