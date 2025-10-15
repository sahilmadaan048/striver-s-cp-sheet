#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> temp(3);
	cin >> temp[0] >> temp[1] >> temp[2];
	sort(temp.begin(), temp.end());
	cout << (abs(temp[0] - temp[1])) + abs(temp[1]-temp[2]) << endl;

	return 0;
}