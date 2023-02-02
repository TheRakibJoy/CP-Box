//Problem - https://toph.co/p/distinct-dishting
int sz;
struct MOS_UP
{
    struct query
    {
        int l,r,id,t;//T is 0 indexed no. of updates
        query() {}
        query(int l,int r,int id,int t)
        {
            this->l=l;
            this->r=r;
            this->t=t;
            this->id=id;
        }
        inline bool operator<(const query &o)const
        {
            if(l/sz!=o.l/sz)
                return l<o.l;
            if(r/sz!=o.r/sz)
                return r<o.r;
            return t<o.t;
        }
    };
    struct update
    {
        int i,nxt,prv;
        update() {}
        update(int i,int nxt,int prv)
        {
            this->i=i;
            this->nxt=nxt;
            this->prv=prv;
        }
    };
    int n,L,R,T;
    long long an;
    vector<int>v;
    vector<query>q;
    vector<update>up;
    unordered_map<int,int>m;
    MOS_UP() {}
    MOS_UP(int n)
    {
        this->n=n;
        v.assign(n,0);
        sz=2*powl(n,0.666666666667);
    }
    void add(int i)
    {
        int x=v[i];
        if(x%3)
            return;
        m[x]++;
        if(m[x]==1)
            an+=x;
    }
    void del(int i)
    {
        int x=v[i];
        if(x%3)
            return;
        m[x]--;
        if(m[x]==0)
            an-=x;
    }
    void updo(int i)
    {
        int j=up[i].i,nxt=up[i].nxt;
        if(j>=L and j<=R)
            del(j);
        v[j]=nxt;
        if(j>=L and j<=R)
            add(j);
    }
    void undo(int i)
    {
        int j=up[i].i,prv=up[i].prv;
        if(j>=L and j<=R)
            del(j);
        v[j]=prv;
        if(j>=L and j<=R)
            add(j);
    }
    void Solve()
    {
        L=1,R=0,T=(int)up.size()-1;
        an=0;
        sort(q.begin(),q.end());
        vector<long long>ans(q.size());
        for(int i=0; i<q.size(); i++)
        {
            int l=q[i].l,r=q[i].r,qt=q[i].t;
            while(T<qt)
                updo(++T);
            while(T>qt)
                undo(T--);
            while(l<L)
                add(--L);
            while(r>R)
                add(++R);
            while(l>L)
                del(L++);
            while(r<R)
                del(R--);
            ans[q[i].id]=an;
        }
        for(auto it:ans)
            cout<<it<<'\n';
    }
};
