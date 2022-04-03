struct Trie
{
    struct node
    {
        node* nxt[26];
        bool endmark;
        node()
        {
            for(int i=0; i<26; i++)
                nxt[i]=NULL;
            endmark=false;
        }
    }*root;
    Trie()
    {
        root = new node();
    }
    void Add(string &s)
    {
        node* cur = root;
        int sz=s.size();
        for(int i=0; i<sz; i++)
        {
            int c=s[i]-'a';
            if(cur->nxt[c]== NULL)
                cur->nxt[c] = new node();
            cur=cur->nxt[c];
        }
        cur->endmark=true;
    }
    int query(string &s)
    {
        node* cur = root;
        int sz=s.size();
        for(int i=0; i<sz; i++)
        {
            int c=s[i]-'a';
            if(cur->nxt[c]== NULL)
                return false;
            cur=cur->nxt[c];
        }
        return cur->endmark;
    }
    void del(node* cur)
    {
        for (int i = 0; i < 26; i++)
            if (cur -> nxt[i])
                del(cur -> nxt[i]);
        delete(cur);
    }
};
