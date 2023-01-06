void d_and_con(int par,int l,int r,int opL,int opR)
{
    if(l>r)
        return;
    int mid=(l+r)>>1;
    dp[mid][par]=inf;
    int opt=opL;
    long long cnt=0;
    for(int i=min(mid,opR); i>=opL; i--)
    {
        long long res=dp[i-1][par-1]+query(i,mid);
        if(res<dp[mid][par])
        {
            dp[mid][par]=res;
            opt=i;
        }
    }
    d_and_con(par,l,mid-1,opL,opt);
    d_and_con(par,mid+1,r,opt,opR);
}
