
// // #include <bits/stdc++.h>
// // using namespace std;

// // int main() {
// //     int n, m;
// //     cin >> n >> m;

// //     if (n == m) {
// //         cout << 0 << endl;
// //         return 0;
// //     }
// //     if(n>m){
// //     	cout << (n-m) << endl;
// //     	return 0;
// //     }

// //     int count = 0;
// //     queue<int> q;
// //     q.push(n);

// //     while (!q.empty()) {
// //         int size = q.size();
// //         count++;
// //         for (int i = 0; i < size; i++) {
// //             int current = q.front();
// //             q.pop();

// //             int multipliedBy2 = current * 2;
// //             int subractedbyone = current -1;

// //             if (multipliedBy2 == m || subractedbyone == m) {
// //                 cout << count << endl;
// //                 return 0;
// //             }

// //             if (multipliedBy2 < m) {
// //                 q.push(multipliedBy2);
// //             }

// //             if (subractedbyone < m) {
// //                 q.push(subractedbyone);
// //             }
// //         }
// //     }

// //     cout << -1 << endl;
// //     return 0;
// // }


// #include<stdio.h>

// int main()
// {
//     int t,n,m;
//     scanf("%d%d",&n,&m);
//     if(n>=m)
//     {
//         t=n-m;
//         printf("%d\n",t);
//     }
//     else
//     {
//         t=0;
//         while(m>n)
//         {
//             if(m&1)
//             {
//                 m++;
//                 t++;
//             }
//             else
//             {
//                 m=m>>1;
//                 t++;
//             }
//         }
//         t=t+n-m;
//         printf("%d\n",t);
//     }
//     return 0;
// }


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

void solve(){
    
}

int main(){
    fast;
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}