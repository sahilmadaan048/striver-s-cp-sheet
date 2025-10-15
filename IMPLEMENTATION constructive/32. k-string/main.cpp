#include<bits/stdc++.h>
using namespace std;

int main(){
	int k;
	cin >> k;
	string s;
	cin >> s;

	int n = s.size();
	if(n%k != 0){
		cout  << "-1";
		return 0;
	}

	unordered_map<char, int> temp;
	for(auto &c : s){
		temp[c]++;
	}

	// string base;
	for(auto& entry : temp){
		if((entry.second % k) !=0 ){
			cout << "-1";
			return 0;
		}
	}

	string base = "";
	for(auto &entry : temp){
		//to make a string of chracracters c repeated n times  ==> string(n, a)
		base += string(entry.second/k, entry.first);
	}

	string result = "";
	for(int i = 0 ; i< k ; i++){
		result += base;
	}
	// reverse(result.begin(), result.end());
	cout << result << endl;
}