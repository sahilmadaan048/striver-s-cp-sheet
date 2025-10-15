#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> temp(2*n);
		for(int i=0; i<2*n; i++){
			cin >> temp[i];
		}
		
		sort(temp.begin(), temp.end());
		cout << abs(temp[n] - temp[n-1]) << endl;	
	}
	return 0;
}