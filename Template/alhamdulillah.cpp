/*starting with the name of almighty ALLAH*/
/*solved by RAKIB JOY*/
// Practice is the only shortcut to improve
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vc vector
#define vi vc<int>
#define vl vc<ll>
#define dbg(x) cout<<x<<endl;
#define mp(x,y) make_pair(x,y)
#define yes dbg("YES")
#define no dbg("NO")
#define tst int t;cin>>t;while(t--)
#define srt(v) sort(v.begin(),v.end());
#define rsrt(v) sort(v.rbegin(),v.rend());
#define rj ios::sync_with_stdio(false);cin.tie(0);
#define rvs(v) reverse(v.begin(),v.end());
#define F first
#define S second
#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define PI 2*acos(0.0)
#define pii pair<int,int>
#define fr(i,a,b) for(ll i=a;i<=b;i++)
#define coutv(v) for(auto it:v)cout<<it<<' ';cout<<endl;
#define cinv(v) for(auto &it:v)cin>>it;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ld long double
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set =tree<T, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>;
*/
//sieve bool b[1000005];void primenire(){int i, j;b[0]=true;b[1]=true;for(i=4; i<=1000000; i+=2){b[i]=true;}for(i=3; i<=1001; i+=2){if(!b[i]){for(j=i*i; j<=1000001; j+=2*i){b[j]=true;}}}}
// power ll power(ll a,ll b){if(b==0)return 1LL;if(b&1)return a*power(a,b-1);else{ll x=power(a,b/2);return x*x;}}
//bigmod long long int m(long long int a,long long int b,long long int c){if(b==0)return 1;if(b%2==0){long long int  tmp=m(a,b/2,c);return ((tmp%c)*(tmp%c))%c;}elsereturn ((a%c)*(m(a,b-1,c)%c))%c;}
//MaxSubarraySum ll mss(vector<ll>v){ll mx=v[0];ll sz=v.size();for(int i=1;i<=sz;i++){ll t=v[i]+v[i-1];if(t>=v[i]) v[i]=t;mx=max(mx,v[i]*1LL);}return mx;}
//combination ll com[1001][1001];void combination(){com[1][1]=1;com[1][0]=1;for(ll i=2; i<=1000; i++){com[i][0]=1;for(ll j=1; j<=i; j++){com[i][j]=com[i-1][j]+com[i-1][j-1];}}}
//euler totient int phi[1000009];void euler(){for(int i=1; i<=1000005; i++)phi[i]=i;for(int i=2; i<=1000005; i++){if(phi[i]==i)for(int j=i; j<=1000005; j+=i){phi[j]/=i;phi[j]*=(i-1);}}}
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

void solve()
{

}
int main()
{
    rj
    //ll t;scanf("%lld",&t);fr(i,1,t) printf("Case %lld: ",i),solve();
    solve();
    return 0;
}
