int LIS(vector<int> &v)
{
    multiset<int>st;

    for(int i=0 ; i<(int)v.size() ; i++){
        auto it = st.lower_bound(v[i]);     ///Use upper bound if u want non-decreasing sub sequence
        if(it != st.end())
            st.erase(it);
        st.insert(v[i]);
    }
    return (int)st.size();
}
