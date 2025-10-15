#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> temp(n);
	for(int i=0; i<n; i++) cin >> temp[i];

	int maxi = 0;
	int j = 0 ;

	while(j<n){
		int count=1;
		for(int i=j+1; i<n; i++){
			if(temp[i] > temp[i-1]){
				count++;
			}
			else break;
		}
		j++;
		maxi = max(maxi, count);
	}

	cout << maxi << endl;
	return 0 ;
}



// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> temp(n);
//     for (int i = 0; i < n; i++) cin >> temp[i];

//     int maxi = 0;
//     int j = 0;

//     while (j < n) {
//         int count = 1;
//         while (j + 1 < n && temp[j + 1] > temp[j]) {
//             count++;
//             j++;
//         }
//         maxi = max(maxi, count);
//         j++;
//     }

//     cout << maxi << endl;
//     return 0;
// }
