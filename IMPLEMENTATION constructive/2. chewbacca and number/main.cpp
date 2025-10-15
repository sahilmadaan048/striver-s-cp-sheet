#include<bits/stdc++.h>
using namespace std;

void modify(string& s){
	if(s[0] >= '5' && s[0] <'9'){
		s[0] = 48 + 57- s[0];
	}
	for(int i=1; i<s.size(); i++){
		if(s[i] >= '5' && s[i] <= '9'){
			s[i] = 48+57- s[i];
		}
	}

	return;
}

int main(){
	long long n;
	cin >> n;
	string s = to_string(n);
	modify(s);
	cout << stoll(s) << endl;
	return 0;
}