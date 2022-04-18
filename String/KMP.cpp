vector<int> make_lps(string &s)
{
    int sz=s.size();
    vector<int> lps(sz);
    int index = 0;
    for (int i = 1; i < sz; )
    {
        if (s[i] == s[index])
            lps[i] = index + 1, ++index, ++i;
        else
        {
            if (index != 0)
                index = lps[index - 1];
            else
                lps[i] = index, ++i;
        }
    }
    return lps;
}
