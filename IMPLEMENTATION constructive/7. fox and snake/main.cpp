#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<char>> mat(n, vector<char>(m, '#'));

	bool check = true;
	for(int i=1; i<n; i+=2){
		if(check){
			for(int j=0; j<m-1; j++){
				mat[i][j] = '.';
			}
		}
		else{
			for(int j=1; j<m; j++){
				mat[i][j] = '.';
			}
		}
		check = !check;
	}


	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << mat[i][j];
		}
		cout << endl;
	}

	return 0;
}