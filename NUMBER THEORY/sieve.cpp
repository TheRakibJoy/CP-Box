bool prime[N+5];
void primenire()
{
    int i, j;
    prime[0]=true;
    prime[1]=true;
    for(i=4; i<=N; i+=2)
    {
        prime[i]=true;
    }
    for(i=3; i*i<=N; i+=2)
    {
        if(!prime[i])
        {
            for(j=i*i; j<=N; j+=2*i)
            {
                prime[j]=true;
            }
        }
    }
}
