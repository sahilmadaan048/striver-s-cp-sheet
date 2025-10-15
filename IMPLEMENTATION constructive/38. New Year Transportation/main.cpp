// https://codeforces.com/problemset/problem/500/A

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m; cin >> n >> m ;
	vector<int> temp(n);
	for(int i=1; i<n; i++) cin >> temp[i];
	int pos = 1;
	while(pos < m){
		pos += temp[pos];
	}
	if(pos == m){
		cout << "YES" << "\n";
	}
	else cout << "NO" << "\n";

	return 0;
}