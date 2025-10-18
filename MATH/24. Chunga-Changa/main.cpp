// https://codeforces.com/problemset/problem/1181/A

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64 x, y, z;
    if (!(cin >> x >> y >> z)) return 0;

    int64 total = (x + y) / z;
    int64 separate = x / z + y / z;

    if (total == separate) {
        cout << total << " " << 0 << "\n";
    } else {
        int64 rx = x % z;
        int64 ry = y % z;
        int64 need_x = (rx == 0 ? z : z - rx);
        int64 need_y = (ry == 0 ? z : z - ry);
        int64 ans_transfer = min(need_x, need_y);
        cout << total << " " << ans_transfer << "\n";
    }
    return 0;
}
