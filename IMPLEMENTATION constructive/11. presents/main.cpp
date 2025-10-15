#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin >> n ;
	vector<int> temp(n);
	for(int i  = 0 ; i< n; i ++){
		cin >> temp[i];
	}

	unordered_map<int, int> map1;
	for(int i  = 0 ; i< n ; i++){
		map1[temp[i]] = i+1;
	}
 
	for(int i =1 ; i<= n ; i++){
		cout << map1[i] << " ";
	}
	return  0 ;
 
}