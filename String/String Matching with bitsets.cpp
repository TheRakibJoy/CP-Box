//Here pos stores every starting pos of ss in s as a substring
bitset<N>bs[26],p;
void solve()
{
    string s;
    cin>>s;
    int a=s.size();
    for(int i=0;i<a;i++)
    {
        bs[s[i]-'a'][i]=1;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        string ss;
        cin>>x>>ss;
        int sz=ss.size();
        p.set();
        for(int i=0;i<sz;i++)
        {
            p&=bs[ss[i]-'a']>>i;
        }
        vector<int>pos;
        for(int i=p._Find_first();i<a;i=p._Find_next(i))
        {
            pos.emplace_back(i);
        }
        if(pos.size()<x)
        {
            cout<<"-1\n";
            continue;
        }
        int ans=INT_MAX;
        for(int i=x-1;i<pos.size();i++)
        {
            ans=min(ans,pos[i]-pos[i-x+1]+sz);
        }
        cout<<ans<<'\n';
    }
}
