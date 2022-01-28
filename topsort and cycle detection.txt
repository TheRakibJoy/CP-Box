vector<int> v;
vector<int> adj[27];
int col[27];
bool isCycle=0;
void cycle_detection(int n)
{
    if(col[n])
    {
        if(col[n]==1)
            isCycle=1;
        return;
    }
    col[n]=1;
    for(auto it:adj[n])
        cycle_detection(it);
    col[n]=2;
    v.push_back(n);
}
