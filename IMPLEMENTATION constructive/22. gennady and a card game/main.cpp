#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	char a = s[0];
	char b = s[1];

	unordered_set<char> s1;
	unordered_set<char> s2;
	for(int i=0; i<5; i++){
		string temp;
		cin >> temp;
		s1.insert(temp[0]);
		s2.insert(temp[1]);
	}

	bool flag = false;
	if(s1.find(a) != s1.end()){
		flag = true;
	}
	if(s2.find(b) != s2.end()){
		flag = true;
	}

	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0 ;
}