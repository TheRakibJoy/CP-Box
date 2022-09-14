struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
    }
    
    size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
    }
};
//FOR pair 
struct custom_hash
{
    size_t operator()(const pair<int,int>&x)const
    {
        return ((long long)x.first)^(((long long)x.second)<<32);
    }
};
//for faster 
mp.reserve(1024);
mp.max_load_factor(0.25);
