#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int count = 0 ;
	while(count != k){
		int num = n%10;
		if(num == 0){
			n /= 10;
			count++;
		}
		else {
			n -= 1;
			count++;
		}
	}
	cout << n << endl;
	return 0;
}