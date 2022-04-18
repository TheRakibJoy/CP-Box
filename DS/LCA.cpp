const int sz=100005;
int sptab[sz][22],lvl[sz],par[sz];
void Init_LCA(int n)
{
    memset(sptab,-1,sizeof sptab);
    for(int i=1 ; i<=n ; i++)
        sptab[i][0] = par[i];
    for(int j=1 ; (1<<j)<=n ; j++)
    {
        for(int i=1 ; i<=n ; i++)
        {
            if(sptab[i][j-1] != -1)
            {
                sptab[i][j] = sptab[sptab[i][j-1]][j-1];
            }
        }
    }
}
int get_LCA(int p,int q)
{
    if(lvl[p] < lvl[q])
        swap(p,q);
    int Log=log2(lvl[p])+1;
    for(int i=Log ; i>=0 ; i--)
    {
        if(lvl[p]-(1<<i) >= lvl[q])
            p = sptab[p][i];
    }
    if(p == q)
        return p;
    for(int i=Log ; i>=0 ; i--)
    {
        if(sptab[p][i]!=-1 && sptab[p][i]!=sptab[q][i])
        {
            p=sptab[p][i];
            q=sptab[q][i];
        }
    }
    return par[p];
}
