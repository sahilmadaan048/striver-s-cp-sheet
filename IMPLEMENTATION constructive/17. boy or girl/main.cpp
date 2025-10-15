#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
	string str;
	cin >> str;
	// cin.ignore();
	unordered_set<char> s;
 
	for(auto &ele : str){
		s.insert(ele);
	}
	int count = 0 ;
	for(auto &ele : s){
		count++;
	}
	if((count & 1) == 1) cout << "IGNORE HIM!" ;
	else cout << "CHAT WITH HER!" ;
}