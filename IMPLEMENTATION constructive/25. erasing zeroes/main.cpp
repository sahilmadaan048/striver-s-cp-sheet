// #include<bits/stdc++.h>
// using namespace std;

// bool cond(string s, int i, vector<int>& temp, vector<int>& temp2){
// 	if(s[i] == '0' && s[i-1] == '1' && temp[i] != 0 ) return true;
// 	else if(s[i] == '0' && s[i-1] == '0' && temp2[i] != 0 && temp[i] != 0) return true;
// 	return false;
// }

// int cnt2(int index, string s){
// 	int count = 0;
// 	for(int i=0; i<index; i++){
// 		if(s[i] == '1'){
// 			count++;
// 		}
// 	}
// 	return count;
// }

// int cnt(int index, string s){
// 	int count = 0 ;
// 	for(int i=index+1; i<s.size(); i++){
// 		if(s[i] == '1'){
// 			count++;
// 		}
// 	}
// 	return count;
// }

// int main(){
// 	int t ;
// 	cin >> t;
// 	cin.ignore();
// 	while(t--){
// 		string s;
// 		cin >> s;
// 		int n= s.size();
// 		int count = 0 ;
// 		vector<int> temp(n), temp2(n);
// 		for(int i=0; i<n; i++){
// 			temp[i] = cnt(i, s);
// 			temp2[i] = cnt2(i, s);
// 		}


// 		for(int i=1; i<n-1; i++){
// 			if(cond(s, i, temp, temp2)){
// 				count++;
// 			}
// 		}

// 		cout << count << endl;
// 	}
// }


#include <bits/stdc++.h>
using namespace std;

bool cond(const string &s, int i, const vector<int>& temp, const vector<int>& temp2) {
    if (s[i] == '0' && s[i - 1] == '1' && temp[i] != 0) return true;
    if (s[i] == '0' && s[i - 1] == '0' && temp2[i] != 0 && temp[i] != 0) return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int count = 0;
        vector<int> temp(n), temp2(n);

        // Calculate temp and temp2 using prefix and suffix counts
        int suffix_count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') suffix_count++;
            temp[i] = suffix_count;
        }

        int prefix_count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') prefix_count++;
            temp2[i] = prefix_count;
        }

        // Check the conditions
        for (int i = 1; i < n - 1; i++) {
            if (cond(s, i, temp, temp2)) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
