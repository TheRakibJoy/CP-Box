vector<int> z_maker(string &s)
{
    int sz=s.size();
    vector<int>zv(sz);
    int l=0,r=0;
    for(int i=1; i<sz; i++)
    {
        if(i<=r)
            zv[i]=min(zv[i-l],r-i+1);
        while(i+zv[i]<sz&&s[zv[i]]==s[i+zv[i]])
            zv[i]++;
        if(i+zv[i]-1>r)
            l=i,r=i+zv[i]-1;
    }
    return zv;
}
