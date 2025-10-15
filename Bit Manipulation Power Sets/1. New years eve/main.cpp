// https://codeforces.com/problemset/problem/912/B

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n,k; cin >> n >> k ;
// 	vector<int> temp(n+1);
// 	for(int i=0; i<n; i++) temp[i]=i+1;
// 	int ans = 0;
// 	vector<int> result;
// 	for(int mask=0 ; mask<(1<<n); mask++){
// 		int maxor = 0; int count = 0;
// 		for(int i=0; i<n; i++){
// 			if(mask & (1<<i)){
// 				maxor ^= temp[i];
// 				count++;
// 			}
// 		}
// 		if(count <= k){
// 			ans = max(maxor, ans);
// 			// break;
// 		}
// 	}
// 	cout << ans << endl;
// 	return 0;
// }

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    // Determine the maximum value which is less than or equal to n and has all bits set
    long long maxValue = 1;
    while (maxValue <= n)
    {
        maxValue <<= 1;
    }
    maxValue -= 1;

    // The maximum XOR value we can get is the max value with all bits set.cout << maxValue << endl;

    return 0;
}
