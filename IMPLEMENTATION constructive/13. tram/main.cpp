#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin >> n;
	cin.ignore();
	vector<int> exit(n);
	vector<int> entry(n);
 
	for(int i = 0 ; i< n ; i++){
		cin >> exit[i] >> entry[i];
	}
 
	vector<int> result(n);
 
	result[0] = entry[0];
	int maxi = result[0];
	for(int i =1; i<n ; i++){
		result[i] = result[i-1] + entry[i]-exit[i];
		maxi = max(maxi, result[i]);
	}
 
	cout << maxi ;
	
}