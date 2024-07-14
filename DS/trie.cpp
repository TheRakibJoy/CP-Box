struct node
{
	int nxt[26];
	bool endmark;
	node()
	{
		for (int i = 0; i < 26; i++)
			nxt[i] = 0;
		endmark = false;
	}
} tr[N * 26];
int root = 1, tt = 1; //tt= total nodes
void Add(string &s)
{
	int cur = root;
	int sz = s.size();
	for (int i = 0; i < sz; i++)
	{
		int c = s[i] - 'a';
		if (tr[cur].nxt[c] == 0)
			tr[cur].nxt[c] = ++tt;
		cur = tr[cur].nxt[c];
	}
	tr[cur].endmark = true;
}
int query(string &s)
{
	int cur = root;
	int sz = s.size();
	for (int i = 0; i < sz; i++)
	{
		int c = s[i] - 'a';
		if (tr[cur].nxt[c] == 0)
			return false;
		cur = tr[cur].nxt[c];
	}
	return tr[cur].endmark;
}
void del(node* cur)
{
	for (int i = 1; i <= tt; i++)
		tr[i] = node();
	tt = 1, root = 1;
}
