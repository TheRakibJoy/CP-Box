struct suf_array
{
    string s;
    int sz;
    vector<int>st,rnk,lcp;
    suf_array() {}
    suf_array(string &ss)
    {
        s=ss;
        s+='$';
        sz=s.size();
        st.resize(sz);
        rnk.resize(sz);
        lcp.resize(sz);
    }
    void count_sort()
    {
        vector<int>cnt(sz);
        for(auto x:rnk)
            cnt[x]++;
        vector<int>st_new(sz);
        vector<int>pos(sz);
        pos[0]=0;
        for(int i=1; i<sz; i++)
            pos[i]=pos[i-1]+cnt[i-1];
        for(auto x:st)
        {
            int i=rnk[x];
            st_new[pos[i]]=x;
            pos[i]++;
        }
        st=st_new;
    }
    void build()
    {
        {
            ///for k=0;
            vector<pair<char,int>>tm(sz);
            for(int i=0; i<sz; i++)
                tm[i]= {s[i],i};
            sort(tm.begin(),tm.end());
            for(int i=0; i<sz; i++)
                st[i]=tm[i].second;
            rnk[st[0]]=0;
            for(int i=1; i<sz; i++)
            {
                if(tm[i].first==tm[i-1].first)
                    rnk[st[i]]=rnk[st[i-1]];
                else
                    rnk[st[i]]=rnk[st[i-1]]+1;

            }
        }
        int k=1;
        while(k<sz)
        {
            for(int i=0; i<sz; i++)
                st[i]=(st[i]-k+sz)%sz;
            count_sort();
            vector<int>rnk_new(sz);
            rnk_new[st[0]]=0;
            for(int i=1; i<sz; i++)
            {
                pair<int,int>pre= {rnk[st[i-1]],rnk[(st[i-1]+k)%sz]};
                pair<int,int>cr= {rnk[st[i]],rnk[(st[i]+k)%sz]};
                if(cr==pre)
                    rnk_new[st[i]]=rnk_new[st[i-1]];
                else
                    rnk_new[st[i]]=rnk_new[st[i-1]]+1;
            }
            rnk=rnk_new;
            k*=2;
        }
    }
    string getsub(int i,int n)
    {
        return s.substr(i,min(n,sz-i));
    }
    int how_many(string &ss)
    {
        int szz=ss.size();
        int lo=0,hi=sz;
        while(lo+1<hi)
        {
            int mid=(lo+hi)>>1;
            string t=getsub(st[mid],szz);
            if(t<=ss)
                lo=mid;
            else
                hi=mid;
        }
        if(getsub(st[lo],szz)!=ss)
            return 0;
        int l=0,r=sz-1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            string t=getsub(st[mid],szz);
            if(t>=ss)
                r=mid;
            else
                l=mid+1;
        }
        return lo-r+1;
    }
    vector<int> get()
    {
        return st;
    }
    void make_lcp()
    {
        int k=0;
        for(int i=0; i<sz-1; i++)
        {
            int pin=rnk[i];
            int j=st[pin-1];
            while(s[i+k]==s[j+k])
                k++;
            lcp[pin]=k;
            k=max(k-1,0);
        }
    }
    vector<int> get_lcp()
    {
        return lcp;
    }
};
