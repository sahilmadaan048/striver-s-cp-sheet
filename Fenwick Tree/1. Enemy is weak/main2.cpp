// https://codeforces.com/contest/61/problem/E

#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define nl cout << "\n"
#define dbg(var) cout << #var << "=" << var << " "
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define srt(v) sort(v.begin(), v.end())         // sort
#define mxe(v) *max_element(v.begin(), v.end()) // find max element in vector
#define mne(v) *min_element(v.begin(), v.end()) // find min element in vector
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed
#define bin(x, y) bitset<y>(x)
using namespace std;
int MOD = 1e9 + 7; // Hardcoded, directly change from here for functions!

void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }
// ================================== take ip/op like vector,pairs directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
// ===================================END Of the input module ==========================================

/*

the number of triplets i, j , k such that i < j < k and a[i] > a[j] > a[k]

a has all distinct elements

- first one thing we can do is brute force
- then optimise it

*/

struct Fenwick
{
    vector<int> bit;
    int n;
    Fenwick(int n)
    {
        this->n = n + 2;
        bit.assign(n + 2, 0);
    }
    void update(int i, int val)
    {
        while (i <= n)
        {
            bit[i] += val;
            i += (i & -i);
        }
    }
    int query(int i)
    {
        int sum = 0;
        while (i > 0)
        {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // step 1 is to do coordinate compression
    // since a[i] >= 1e9
    // and we cant have that much indexing in the BIT array

    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    // lets remove the duplicates from hee
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    // m,mapping the unique value on the vals array to the 1 based index position of t hat element in the sorted version of the given arrays(vals)
    for (int i = 0; i < n; i++)
    {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1; // to convert to 1 based indexing
    }

    Fenwick bitLeft(n), bitRight(n);

    vector<int> leftGreater(n);  // lg[i] stores the number of greater elements on thw left of the index i
    vector<int> rightSmaller(n); // rg[i] stores the number of greater elements onn the right side of the index i
    for (int i = 0; i < n; i++)
    {
        int smallerOrEqual = bitLeft.query(a[i]); 

        // leftGreater[i] = (total elements before i) - (number of smallerOrEqual)
        //         = i - bitLeft.query(a[i])

        leftGreater[i] = i - smallerOrEqual;
        bitLeft.update(a[i], 1); // Then we insert the current element into the Fenwick tree:
    }

    for (int i = n - 1; i >= 0; i--)
    {
        rightSmaller[i] = bitRight.query(a[i] - 1);
        bitRight.update(a[i], 1);
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += leftGreater[i] * rightSmaller[i];
    }

    cout << sum << "\n";
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
