///Must make the string 1 indexed
struct Palindromic_tree
{
    struct node
    {
        int nxt[26];
        int sz;
        int link;
        int tot; /// total number of palindrome ends here
        int fre; /// frequency of current palindrome
        int start;
    };
    string s;
    vector<node>t;
    int id,tt,a; /// tt -> last processed node
    Palindromic_tree(string ss)
    {
        s=ss;
        a=s.size();
        t=vector<node>(a+3);
        t[1].sz=-1,t[1].link=1;
        t[2].sz=0,t[2].link=1;
        tt=id=2;
    }
    int Get_link(int x,int i)
    {
        while(s[i-t[x].sz-1]!=s[i])
            x=t[x].link;
        return x;
    }
    bool Extend(int i)
    {
        tt=Get_link(tt,i);
        int cur=t[tt].link,c=s[i]-'a';
        cur=Get_link(cur,i);

        if(!t[tt].nxt[c]) /// new palindrome
        {
            t[tt].nxt[c]=++id;
            t[id].sz=t[tt].sz+2;
            t[id].link=t[id].sz==1?2:t[cur].nxt[c];
            t[id].tot=1+t[t[id].link].tot;
            tt=t[tt].nxt[c];
            t[tt].fre=1;
            t[tt].start=i-t[tt].sz+1;
            return true;
        }
        tt=t[tt].nxt[c];
        t[tt].fre++;
        return false;
    }
    int how_many()
    {
        int ans=0;
        for(int i=id; i>2; i--)
        {
            t[t[i].link].fre+=t[i].fre;
            ans+=t[i].fre;
        }
        return ans;
    }
};
