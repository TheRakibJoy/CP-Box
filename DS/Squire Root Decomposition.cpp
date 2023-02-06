struct SQD
{
    string s;
    int cnt[450][26];
    int a,sz;
    char lazy[450];
    int bno(int in)
    {
        return in/sz;
    }
    int getl(int bl)
    {
        return sz*bl;
    }
    int getr(int bl)
    {
        return min(a-1,sz*(bl+1)-1);
    }
    SQD() {}
    SQD(string &s)
    {
        this->s=s;
        a=s.size();
        sz=sqrtl(a);
        memset(cnt,0,sizeof cnt);
        memset(lazy,0,sizeof lazy);
        for(int i=0; i<a; i++)
        {
            int c=s[i]-'a';
            cnt[bno(i)][c]++;
        }
    }
    void clrlzy(int n)
    {
        if(lazy[n]==0)
            return;
        for(int i=getl(n); i<=getr(n); i++)
        {
            s[i]=lazy[n];
        }
        lazy[n]=0;
    }
    void clr(int n)
    {
        for(int i=0; i<26; i++)
            cnt[n][i]=0;
    }
    void update(int l,int r,char c)
    {
        int lf=bno(l),rt=bno(r);
        for(int i=lf+1; i<rt; i++)
        {
            clr(i);
            lazy[i]=c;
            cnt[i][c-'a']=sz;
        }
        clrlzy(lf);
        for(int i=l; i<=min(r,getr(lf)); i++)
        {
            int ch=s[i]-'a';
            cnt[lf][ch]--;
            s[i]=c;
            ch=s[i]-'a';
            cnt[lf][ch]++;
        }
        if(lf!=rt)
        {
            clrlzy(rt);
            for(int i=getl(rt); i<=r; i++)
            {
                int ch=s[i]-'a';
                cnt[rt][ch]--;
                s[i]=c;
                ch=s[i]-'a';
                cnt[rt][ch]++;
            }
        }
    }
    vector<int>query(int l,int r)
    {
        vector<int>ans(26);
        int lf=bno(l),rt=bno(r);
        for(int i=lf+1; i<rt; i++)
        {
            for(int j=0; j<26; j++)
                ans[j]+=cnt[i][j];
        }
        clrlzy(lf);
        for(int i=l; i<=min(r,getr(lf)); i++)
        {
            int ch=s[i]-'a';
            ans[ch]++;
        }
        if(lf!=rt)
        {
            clrlzy(rt);
            for(int i=getl(rt); i<=r; i++)
            {
                int ch=s[i]-'a';
                ans[ch]++;
            }
        }
        return ans;
    }
};
