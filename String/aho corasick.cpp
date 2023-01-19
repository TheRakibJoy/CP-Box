//template from rkb_rd
const int option = 26,base = 'a';
struct Aho_vajita
{
    struct node
    {
        char ech;       /// incoming edge's character
        int link;       /// suffix link
        int go[option];  /// where to go from here
        int leaf;       /// is it a last character
        int par;         /// index of parent node
        int occ;        /// how many
        int level;      ///length
        int nxt[option]; /// indices of child node
        int exit;       /// exit link
    };

    int tt;
    vector<node>t;
    stack<int>stk;  /// storing nodes according to their depth

    Aho_vajita()
    {
        tt=0;
        t=vector<node>(1);
        t[tt].level=0;
    }
    int Add(string &s)
    {
        int cur=0;
        for(int i=0; i<s.size(); i++)
        {
            int c=s[i]-base;
            if(!t[cur].nxt[c])
            {
                t[cur].nxt[c]=++tt;
                t.emplace_back();
                t[tt].par=cur;
                t[tt].level=t[cur].level+1;
                t[tt].ech=s[i];
            }
            cur=t[cur].nxt[c];
        }
        t[cur].leaf=1;
        return cur;
    }
    void Build()
    {
        queue<int>q;
        q.push(0);

        while(!q.empty())
        {
            int cur=q.front();
            stk.push(cur);
            q.pop();
            /// suffix link
            if(cur==0||t[cur].par==0)
                t[cur].link=0;
            else
                t[cur].link=t[t[t[cur].par].link].go[t[cur].ech-'a'];
            /// exit link
            if(cur==0||t[cur].par==0)
                t[cur].exit=0;
            else if(t[t[cur].link].leaf)
                t[cur].exit=t[cur].link;
            else
                t[cur].exit=t[t[cur].link].exit;
            /// update go
            for(int c=0; c<option; c++)
                if(t[cur].nxt[c])
                    t[cur].go[c]=t[cur].nxt[c];
                else
                    t[cur].go[c]=(cur==0)?0:t[t[cur].link].go[c];

            for(int c=0; c<option; c++)
                if(t[cur].nxt[c])
                    q.push(t[cur].nxt[c]);
        }
    }
    void Search(string &s) /// number of occurences
    {
        int cur=0;
        for(int i=0; i<s.size(); i++)
        {
            int c=s[i]-'a';
            cur=t[cur].go[c];
            t[cur].occ++;
        }
        while(!stk.empty())
        {
            int i=stk.top();
            stk.pop();
            t[t[i].link].occ+=t[i].occ;
        }
    }
};
