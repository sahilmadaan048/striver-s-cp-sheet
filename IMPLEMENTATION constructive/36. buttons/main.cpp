// https://codeforces.com/contest/268/problem/C

// #include<bits/stdc++.h>
// using namespace std;

// //1×n+2×(n−1)+3×(n−2)+⋯+n×1 will be the sum of all prsses

// int main()
// {
//     long long n,sum,i;
//     while(cin>>n)
//     {
//         sum=n;
//         for(i=1;i<n;i++){
//             sum+=(n-i)*i;
//         }
//         cout<<sum<<endl;
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// bool solve(int x1, int x2 , int y1, int y2){
// 	// bool flag = false;
// 	//the coordinates must be integers

// 	//for any two points fromm the set, the distance between them is a non integer
// 	double dist =sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
// 	int temp = dist;
// 	return temp == dist;
// 	// return flag;
// }

// int main(){
// 	// int t; cin >> t;
// 	// set
// 	vector<vector<int>> temp;
// 		int n, m; cin >> n >> m ;
// 		for(int i=0; i<=n; i++){
// 			for(int j=0; j<=m; j++){
// 				temp.push_back({i, j});
// 		}
// 	}

// 	int size = temp.size();

// 	set<pair<int, int>> st;
// 	for(int i=0 ;i<size-1; i++){
// 		for(int j=i+1;j<size; j++){
//                 if (solve(temp[i][0], temp[i][1], temp[j][0], temp[j][1])) {
//                     st.insert({temp[i][0], temp[i][1]});
//                     st.insert({temp[j][0], temp[j][1]});
//                 }
// 		}
// 	}

// 	cout << st.size() << "\n";
// 	for(auto pair: st){
// 		cout << pair.first << " " << pair.second << "\n";
// 	}

// 	return 0 ;
// }

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Find the minimum of n and m
    int k = min(n, m);

    // The size of the beautiful set is k + 1
    cout << k + 1 << "\n";

    // Output the beautiful set points
    for (int i = 0; i <= k; i++) {
        cout << i << " " << (m - i) << "\n";
    }

    return 0;
}


