#include<bits/stdc++.h>
using namespace std;
 
int countLucky(long long &num){
	int count = 0 ;
	while(num){
		int ld = num%10;
		if(ld == 4 || ld == 7) count++;
		num /= 10;
	}
	return count;

}
 
int main(){
	long long n;
	cin >> n;
	cin.ignore();
 
	int lucky_count = countLucky(n);
 
	if(lucky_count == 4 || lucky_count == 7) cout << "YES" ;
	else cout << "NO" ;
 
}