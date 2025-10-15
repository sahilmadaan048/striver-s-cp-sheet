#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 2e5 + 7;
const ll maxn = N;

struct Fenwick
{
    ll BIT[maxn]; // maxn is the  size it is storing 0 in all dabbas initially while initialising 

    // query prefix sum from 1..i (0 based input)
    ll query(ll id)
    {
        id++; // make it 1 based internally
        ll sum = 0;
        while (id > 0)
        {
            sum += BIT[id];
            id -= (id & -id);
        }
        return sum;
    }

    // Add 'val' to element at index i (0-based)
    void update(ll id, ll val)
    {
        id++;
        while (id <= maxn)
        {
            BIT[id] += val;
            id += (id & -id);
        }
    }

    // Range update: add 'val' to range [l, r] (0-based)
    void range_update(ll l, ll r , ll val) {
        update(l, val);  // start adding val from index l onward
        update(r+1, -val); // stop adding val after index r
    }

} fenw;

int main()
{

    int n = 10;
    vector<int> arr(n, 0);

    // Example usage
    fenw.range_update(2, 5, 10); // add 10 to range [2,5]
    fenw.range_update(0, 3, 5);  // add 5 to range [0,3]

    cout << "Value at index 3: " << fenw.query(3) << "\n";
    cout << "Value at index 6: " << fenw.query(6) << "\n";

    return 0;
}