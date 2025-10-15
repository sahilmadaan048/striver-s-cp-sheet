#include<bits/stdc++.h>
using namespace std;
 
int main(){
	string s;
	cin >> s;
 
	string temp = "";
	for(auto &ele : s){
		if(ele!='+') temp.push_back(ele);
	}
	sort(temp.begin(), temp.end());
	cout << temp[0];
	for(int i =1 ; i<temp.size() ; i++){
		cout << '+' << temp[i];
	}
}