const int B=18;
int t[N][B], v[N];
void build(int n) {
  for(int i = 1; i <= n; ++i) t[i][0] = v[i];
  for(int k = 1; k < B; ++k) {
    for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
      t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
    }
  }
}
int RmnQ(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  return min(t[l][k], t[r - (1 << k) + 1][k]);
}
