struct Mat
{
    vector<vector<int>>m;
    int x,y;
    Mat(int _x,int _y)
    {
        x=_x,y=_y;
        m.assign(x,vector<int> (y,0));
    }
    inline Mat operator + (const Mat &mt)
    {
        assert(x==mt.x&&y==mt.y);
        Mat ans(x,y);
        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                ans.m[i][j]=(m[i][j]+mt.m[i][j])%mod;
            }
        }
        return ans;
    }
    inline Mat operator - (const Mat &mt)
    {
        assert(x==mt.x&&y==mt.y);
        Mat ans(x,y);
        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                ans.m[i][j]=(m[i][j]-mt.m[i][j])%mod;
            }
        }
        return ans;
    }
    inline Mat operator * (const Mat &mt)
    {
        assert(y==mt.x);
        Mat ans(x,mt.y);
        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < mt.y; j++)
            {
                for(int k = 0; k < y; k++)
                {
                    ans.m[i][j] = (ans.m[i][j] + 1LL * m[i][k] * mt.m[k][j] % mod) % mod;
                }
            }
        }
        return ans;
    }
    inline void make_iden()
    {
        assert(x==y);
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < x; j++)
                m[i][j] = i == j;
        }
    }
};
