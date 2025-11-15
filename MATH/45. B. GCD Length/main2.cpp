#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long a, b, c;
        cin >> a >> b >> c;

        long long g = 1;
        for (int i = 1; i < c; i++) g *= 10;

        long long x = g;
        for (int i = 0; i < a - c; i++) x *= 10;

        long long y = g;
        for (int i = 0; i < b - c; i++) y *= 10;
        y += g;   // ensures gcd(x, y) = g

        cout << x << " " << y << "\n";
    }
}
