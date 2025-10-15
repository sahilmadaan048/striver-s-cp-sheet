#include<bits/stdc++.h>
using namespace std;

bool isValid(string s, string t, string p){
	return (s == t || s== p);
}

bool islower(char c){
	return c>='a' && c<='z';
}

void modify(int i, string& s){
	if(islower(s[i])){
		transform(s.begin()+i, s.begin()+1+i, s.begin()+i, ::toupper);
	}
	else {
		transform(s.begin()+i, s.begin()+1+i, s.begin()+i, ::tolower);
	}
}

int main(){
	string s;
	cin >> s;
	string t = s;
	transform(t.begin(), t.begin()+1, t.begin(), ::tolower);
	transform(t.begin()+1, t.end(), t.begin()+1, ::toupper);

	string p = s;
	transform(p.begin(), p.end(), p.begin(), ::toupper);

 	if(isValid(s, t, p)){
 		//now chnage the letters from uppercase to lower case
 		//ans vice versa
 		for(int i=0; i<s.size(); i++){
 			modify(i, s);
 		}
 	}
 	cout << s << endl;
}