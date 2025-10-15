#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

class Fenwick
{
public:
    vector<ll> B1, B2;
    int n;

    Fenwick(int n)
    {
        this->n = n;
        B1.resize(n + 1, 0);
        B2.resize(n + 1, 0);
    }
    void add(vector<ll> &b, int idx, ll x)
    {
        while (idx <= n)
        {
            b[idx] += x;
            idx += (idx & -idx);
        }
    }

    // Range update: add x to [l, r]
    void rangeAdd(int l, int r, ll x)
    {
        add(B1, l, x);
        add(B1, r + 1, -x);
        add(B2, l, x * (l - 1));
        add(B2, r + 1, -x * r);
    }
    /*
    We’ll soon see why, but for now:

B1 stores how much slope (x per element) we add.

B2 stores a correction so we don’t overcount when computing prefix sums.


For B2:

We need it to correct the overcount when we take prefix sums.

When we compute i * sum(B1, i),
we are effectively multiplying the slope by i —
but that adds extra area before l.

To fix that, we subtract a compensating value in B2.

Through algebra (which comes from prefix sum derivation), the correct adjustment turns out to be:

*/

    ll sum(vector<ll> &b, int idx)
    {
        ll total = 0;
        while (idx > 0)
        {
            total += b[idx];
            idx -= (idx & -idx);
        }
        return total;
    }

    ll prefSum(int idx)
    {
        return sum(B1, idx) * idx - sum(B2, idx);
    }
    /*
    This magical formula gives the correct cumulative sum at position i.

    Let’s understand how it works via updates.

    */

    // Range query: sum in [l, r]
    ll rangeSum(int l, int r)
    {
        return prefSum(r) - prefSum(l - 1);
    }
};

int main()
{
    int n = 10;
    Fenwick fenw(n);

    // Add +5 to range [2,6]
    fenw.rangeAdd(2, 6, 5);

    // Add +3 to range [4,9]
    fenw.rangeAdd(4, 9, 3);

    cout << "Sum of range [3,7]: " << fenw.rangeSum(3, 7) << "\n";
    cout << "Sum of range [1,10]: " << fenw.rangeSum(1, 10) << "\n";

    return 0;
}
