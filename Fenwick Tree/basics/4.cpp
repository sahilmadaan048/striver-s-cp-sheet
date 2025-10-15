#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Fenwick
{
    vector<ll> bit;
    int n;
    Fenwick(int n)
    {
        this->n = n + 2;
        bit.assign(n + 2, 0);
    }
    void update(int i, ll val)
    {
        while (i <= n)
        {
            bit[i] += val;
            i += (i & -i);
        }
    }
    ll query(int i)
    {
        ll sum = 0;
        while (i > 0)
        {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
};

int main()
{
    return 0;
}