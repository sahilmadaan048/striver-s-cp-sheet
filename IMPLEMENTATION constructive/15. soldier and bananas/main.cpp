#include<bits/stdc++.h>
using namespace std;

int main(){
	int k, n, w;
	cin >> k >> n >>w;
	int diff = ((k)*(w)*(w+1)/2)-n;
	cout << ((diff)<0 ? (0) : (diff)) << endl ;
}