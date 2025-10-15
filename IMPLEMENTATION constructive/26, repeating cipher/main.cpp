#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans ="";
	int num=1;
	int d = 1;
	for(int i=0; i<n; i+=num){
		ans.push_back(s[i]);
		num += d;
	}
	cout << ans << endl;
}