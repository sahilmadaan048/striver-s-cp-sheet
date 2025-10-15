#include<bits/stdc++.h>
using namespace std;

int ans(char ch){
	if(ch == 'T') return 4;
	else if(ch == 'C') return 6;
	else if(ch == 'O') return 8;
	else if(ch == 'D') return 12;
	else if(ch == 'I') return 20;
}

int main(){
	int t;
	cin >> t;
	vector<char> temp;
	while(t--){
		string s;
		cin >> s;
		temp.push_back(s[0]);
	}
	int count = 0;
	for(const auto &ele : temp){
		count += ans(ele);
	}

	cout << count << endl;
	return 0;
}