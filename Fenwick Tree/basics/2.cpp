#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct FenwickTree
{
    vector<ll> bit;
    ll n;

    FenwickTree(ll n)
    {
        this->n = n + 1;
        bit.assign(n + 1, 0ll);
    }

    // Add 'val' to index idx
    void add(ll idx, ll val)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

    // Add 'val' to range [l, r]
    void range_add(ll l, ll r, ll val)
    {
        add(l, val);
        add(r + 1, -val);
    }

    // Get value at index idx
    ll get(ll idx)
    {
        ll ret = 0;
        for (++idx; idx > 0ll; idx -= idx & -idx)
        {
            ret += bit[idx];
        }

        return ret;
    }
};

int main()
{
    int n = 8;
    FenwickTree ft(n);

    ft.range_add(1, 4, 10);
    ft.range_add(3, 6, 5);

    for (int i = 0; i < n; i++)
    {
        cout << "Value at index " << i << " = " << ft.get(i) << "\n";
    }

    return 0;
}