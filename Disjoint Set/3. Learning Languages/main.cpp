// https://codeforces.com/problemset/problem/277/A


#include <bits/stdc++.h>
using namespace std;
#define ll             long long int 
#define ulli           unsigned long long int 
#define li             long int 
#define ff(i,a,b)      for(int i=a;i<b;i++)
#define fb(i,b,a)      for(int i=b;i>=a;i--)
#define w(t)           while(--t >= 0)
#define l(s)           s.length()
#define ci(n)          cin>>n;
#define fast           ios_base::sync_with_stdio(false);
#define sa(a,n)        sort(a,a+n)
#define sv(v)          sort(v.begin(),v.end())
#define cy             cout<<"YES\n"
#define cn             cout<<"NO\n"
#define nl             cout<<"\n"
#define minus          cout<<"-1\n";
#define vi             vector<int>
#define pb             push_back
#define tc             int t; cin>>t;
#define pp             pair<int,int>
#define input(a,n)     for(int i=0;i<n;i++) cin>>a[i];
#define mod            1000000007
#define co(n)          cout<<n;
#define ret            return 0
#define mi             map<int,int>
#define output(a,n)    for(int i=0;i<n;i++) cout<<a[i]<<" ";   
#define forn(i, n)     ff(i, 0, n)
#define sz(v)          int((v).size())


vector<vector<int>> employee_languages;
vector<bool> visited;
int n, m;

void dfs(int emp, const vector<set<int>>& lang_to_employees) {
    visited[emp] = true;
    for (int lang : employee_languages[emp]) {
        for (int other_emp : lang_to_employees[lang]) {
            if (!visited[other_emp]) {
                dfs(other_emp, lang_to_employees);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    employee_languages.resize(n);
    visited.resize(n, false);
    vector<set<int>> lang_to_employees(m + 1);

    bool no_languages = true;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if (k > 0) no_languages = false;
        for (int j = 0; j < k; ++j) {
            int lang;
            cin >> lang;
            employee_languages[i].push_back(lang);
            lang_to_employees[lang].insert(i);
        }
    }

    if (no_languages) {
        cout << n << endl;
        return 0;
    }

    int components = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, lang_to_employees);
            components++;
        }
    }

    cout << components - 1 << endl;
    return 0;
}