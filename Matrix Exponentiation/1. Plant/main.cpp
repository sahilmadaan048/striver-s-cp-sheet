#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

long long modpow(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
   long long n;
    cin >> n;

    if (n == 0) {
        cout << 1; 
        return;
    }

    long long p1 = modpow(2, 2 * n - 1) % MOD;  // 2^(2n - 1)
    long long p2 = modpow(2, n - 1) % MOD;      // 2^(n - 1)
    long long ans = (p1 + p2) % MOD;

    cout << ans << "\n";
    return;
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T  = 1;  
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    