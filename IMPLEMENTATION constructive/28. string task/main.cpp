/*
───▄▀▀▀▄▄▄▄▄▄▄▀▀▀▄───
───█▒▒░░░░░░░░░▒▒█───
────█░░█░░░░░█░░█────
─▄▄──█░░░▀█▀░░░█──▄▄─
█░░█─▀▄░░░░░░░▄▀─█░░█

Author- Sahil Madaan

*/

#include<bits/stdc++.h>
using namespace std;
 
bool isConso(char c){
	return (c!='a' && c!='o' && c!= 'y' && c!= 'e' && c!='u' && c!='i');
}
 
int main(){
	string s;
	getline(cin, s);
 
	//transform to lower case
	transform(s.begin(), s.end(), s.begin(), ::tolower);
 
	//remove all the vowels 
	string result = "";
	for(auto &ele : s){
		if(isConso(ele)){
			result += "." ;
			result += ele;
		}
	}
 
	cout << result << endl;
}