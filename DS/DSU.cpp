int par[N+5];
void init()
{
   fr(i,1,N) par[i]=i;
}
int get(int n)
{
   if(par[n]==n) return n;
   return par[n]=get(par[n]);
}
void uni(int a,int b)
{
   par[a]=b;
}
