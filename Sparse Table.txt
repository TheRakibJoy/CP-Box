int v[N+5];
int sptab[N+5][26];
int Log[N+5];
void LogPreCalc()
{
    Log[1]=0;
    for(int i=2; i<=N; i++)
        Log[i]=Log[i/2]+1;
}
void SPgen(int n)
{
    for(int i=1; i<=n; i++)
        sptab[i][0]=v[i];
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i+(1<<j)-1<=n; i++)
        {
            sptab[i][j]=min(sptab[i][j-1],sptab[i+(1<<(j-1))][j-1]);
        }
    }
}
int RmnQ(int lo,int hi)
{
    int x=Log[hi-lo+1];
    return min(sptab[lo][x],sptab[hi-(1<<x)+1][x]);
}
long long RngSum(int lo,int hi,int n)
{
    long long ans=0;
    for(int j=(int)log2(n*1.0)+1 ; j>=0 ; j--)
    {
        if((1<<j) <= hi-lo+1)
        {
            ans += sptab[lo][j];
            lo += (1<<j);
        }
    }
    return ans;
}
