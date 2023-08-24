/*template from neal*/
struct Cool_Bitset {
   vector<uint64_t> bits;
   int64_t b, n;
 
   Cool_Bitset(int64_t _b = 0) {
      init(_b);
   }
 
   void init(int64_t _b) {
      b = _b;
      n = (b + 63) / 64;
      bits.assign(n, 0);
   }
 
   void clear() {
      b = n = 0;
      bits.clear();
   }
 
   void reset() {
      bits.assign(n, 0);
   }
 
   void _clean() {
      // Reset all bits after `b`.
      if (b != 64 * n)
         bits.back() &= (1LLU << (b - 64 * (n - 1))) - 1;
   }
 
   bool get(int64_t index) const {
      return bits[index / 64] >> (index % 64) & 1;
   }
 
   void set(int64_t index, bool value) {
      assert(0 <= index && index < b);
      bits[index / 64] &= ~(1LLU << (index % 64));
      bits[index / 64] |= uint64_t(value) << (index % 64);
   }
 
   // Simulates `bs |= bs << shift;`
   void left_shift(int64_t shift) {
      int64_t div = shift / 64, mod = shift % 64;
 
      if (mod == 0) {
         for (int64_t i = n - 1; i >= div; i--)
            bits[i] |= bits[i - div];
 
         return;
      }
 
      for (int64_t i = n - 1; i >= div + 1; i--)
         bits[i] |= bits[i - (div + 1)] >> (64 - mod) | bits[i - div] << mod;
 
      if (div < n)
         bits[div] |= bits[0] << mod;
 
      _clean();
   }
 
   // Simulates `bs |= bs >> shift;`
   void right_shift(int64_t shift) {
      int64_t div = shift / 64, mod = shift % 64;
 
      if (mod == 0) {
         for (int64_t i = div; i < n; i++)
            bits[i - div] |= bits[i];
 
         return;
      }
 
      for (int64_t i = 0; i < n - (div + 1); i++)
         bits[i] |= bits[i + (div + 1)] << (64 - mod) | bits[i + div] >> mod;
 
      if (div < n)
         bits[n - div - 1] |= bits[n - 1] >> mod;
 
      _clean();
   }
 
   int64_t find_first() const {
      for (int i = 0; i < n; i++)
         if (bits[i] != 0)
            return 64 * i + __builtin_ctzll(bits[i]);
 
      return -1;
   }
   int64_t find_next(int x) const {
      for (int i = x + 1; i < x + 64; i++)
      {
         if (get(i))
            return i;
      }
      for (int i = x / 64 + 1; i < n; i++)
         if (bits[i] != 0)
            return 64 * i + __builtin_ctzll(bits[i]);
 
      return INT_MAX;
   }
 
   Cool_Bitset& operator&=(const Cool_Bitset &other) {
      assert(b == other.b);
 
      for (int i = 0; i < n; i++)
         bits[i] &= other.bits[i];
 
      return *this;
   }
};
