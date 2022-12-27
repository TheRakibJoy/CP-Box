//Samllest element is in the front
struct monotonic_queue
{
    deque<pair<int,int> >dq;
    void add(int val,int in)
    {
        while(!dq.empty()&&dq.back().first>=val) //strictly increasing order
            dq.pop_back();
        dq.push_back({val,in});
    }
    void del(int in)
    {
        if(!dq.empty() && dq.front().second==in)
            dq.pop_front();
    }
};
