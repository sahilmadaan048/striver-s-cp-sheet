#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(){
	int n;
	cin >> n;
	int a[n+1];
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	int ans =1;
	for(int i=1; i<=n; i++){
		int node=a[i];
		int dep=1;
		while(node != -1){
			node=a[node];
			dep++;
		}
		ans=max(ans, dep);
	}
	cout << ans << endl;
	return 0;
}

int main(){
	int testcase=1;
	while(testcase--){
		solve();
	}
	return 0;
}