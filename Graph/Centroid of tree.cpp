int get_cen(int n,int par)
{
    for(auto it:adj[n])
    {
        if(it==par)
            continue;
        if(sz[it]>size_of_tree/2)
            return get_cen(it,n);
    }

    return n;
}
