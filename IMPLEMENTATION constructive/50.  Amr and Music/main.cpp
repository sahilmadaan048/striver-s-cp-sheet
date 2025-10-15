    // https://codeforces.com/problemset/problem/507/A

    #include "bits/stdc++.h"
    using namespace std;

    void solve(){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        int total = k;
        int count = 0;
        vector<int> ind;
        for(int i=0; i<n; i++) {
            if(a[i] <= total) {
                count++;
                total -= a[i];
                ind.push_back(i+1);
            } 
            if(total == 0) break;
        }
        cout << count << "\n";
        for(auto ele : ind) cout << ele << " ";
        return;
    }

    int32_t main()
    {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        int T = 1;
        while (T--)
        {
            solve();
        }
        return 0;
    }

        