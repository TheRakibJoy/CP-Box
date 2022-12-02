///counting the max sum of max frequent color 
///for every subtree
int a;
vi adj[N];
int sz[N],col[N],cnt[N];
vi nodes[N];
long long mxcol=0,sum[N],ans[N];
void count_size(int n,int p)
{
    sz[n]=1;
    for(auto it:adj[n])
    {
        if(it==p)
            continue;
        count_size(it,n);
        sz[n]+=sz[it];
    }
}
void dsu(int n,int p,bool keep)
{
    int Max = -1,bigchild = -1;
    for(auto it:adj[n])
    {
        if(it!=p&&sz[it]>Max)
        {
            Max=sz[it];
            bigchild=it;
        }
    }
    for(auto it:adj[n])
    {
        if(it!=p&&it!=bigchild)
        {
            dsu(it,n,0);
        }
    }
    if(bigchild!=-1)
    {
        dsu(bigchild,n,1);
        swap(nodes[n],nodes[bigchild]);
    }
    nodes[n].push_back(n);
    cnt[col[n]]++;
    sum[cnt[col[n]]]+=col[n];
    if(cnt[col[n]]>mxcol)
    {
        mxcol++;
    }
    for(auto u:adj[n])
    {
        if(u==p||u==bigchild)
            continue;
        for(auto it:nodes[u])
        {
            nodes[n].push_back(it);
            cnt[col[it]]++;
            sum[cnt[col[it]]]+=col[it];
            if(cnt[col[it]]>mxcol)
            {
                mxcol++;
            }
        }
    }
    ans[n]=sum[mxcol];
    if(keep==0)
    {
        for(auto it:nodes[n])
        {
            sum[cnt[col[it]]]-=col[it];
            cnt[col[it]]--;
            if(sum[mxcol]==0)
            {
                mxcol--;
            }
        }
    }

}
