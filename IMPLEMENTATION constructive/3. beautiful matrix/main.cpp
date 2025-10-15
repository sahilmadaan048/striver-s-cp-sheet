#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<vector<int>> mat(5, vector<int>(5, 0));

	int rowIndex = 0;
	int colIndex = 0;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			cin >> mat[i][j];
			if(mat[i][j] == 1){
				rowIndex = i;
				colIndex = j;
				break;
			}
		}
	}

	cout << abs(rowIndex-2) + abs(colIndex-2) << endl;
	return 0;
}