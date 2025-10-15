#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	bool flag = true;
	while(t--){
		int n;
		cin >> n;
		if(n == 1){
			flag = false;
			break;
		}
	}

	if(flag) cout << "EASY" << endl;
	else cout << "HARD" << endl;

	return 0;
}