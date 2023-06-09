//From YouxnowWho
#include<bits/stdc++.h>
using namespace std;
int main() {
    int i, j, x, n, m;
    string s;
    cin >> s;
    n = s.size();
    vector<int> ep(n);  // maximum even length palindrome centered at i
    // here ep[i]=the palindrome has ep[i]-1 right characters from i
    // e.g. for abba, ep[2]=2;
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int x = (i > r) ? 0 : min(ep[l + r - i + 1], r - i + 1);
        while (0 <= i - x - 1 && i + x < n && s[i - x - 1] == s[i + x]) {
            x++;
        }
        ep[i] = x--;
        if (i + x > r)
        {
            l = i - x - 1;
            r = i + x ;
        }
    }
    vector<int> op(n);  // maximum odd length palindrome centered at i
    // here op[i]=the palindrome has op[i]-1 right characters from i
    // e.g. for eye, op[1]=2;
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int x = (i > r) ? 1 : min(op[l + r - i], r - i);
        while (0 <= i - x && i + x < n && s[i - x] == s[i + x]) {
            x++;
        }
        op[i] = x--;
        if (i + x > r)
        {
            l = i - x;
            r = i + x;
        }
    }
    return 0;
}
