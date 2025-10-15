// #include<bits/stdc++.h>
// using namespace std;

// // int gcd(int a, int b) {
// //     while (b != 0) {
// //         int temp = b;
// //         b = a % b;
// //         a = temp;
// //     }
// //     return a;
// // }

// // Function to calculate the LCM of two numbers
// // int lcm(int a, int b) {
// //     return (a / gcd(a, b)) * b;
// // }

// // int main(){
// // 	int n, m;
// // 	cin >> n >> m;

// // 	//write code to calculate the index scuh that the element of that index in fibo series is n input
// // 	int index = 0;
// // 	int prev2 = 0 ;
// // 	int prev =1;
// // 	int curi =0;
// // 	while(curi < n){
// // 		curi = prev2+prev;
// // 		prev2=prev;
// // 		prev = curi;
// // 		index++;
// // 		if(curi == n and index%m == 0){
// // 			cout << index << "\n";
// // 			return 0;
// // 		}
// // 	}

// // 		// if(index < m){
// // 		// 	cout << -1 << endl;
// // 		// 	return 0 ;
// // 		// }
// // 	cout << -1 << "\n";
// // 	// cout << lcm(index, m) << endl;
// // 	// cout << index;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// // Function to calculate the GCD of two numbers
// // int gcd(int a, int b) {
// //     while (b != 0) {
// //         int temp = b;
// //         b = a % b;
// //         a = temp;
// //     }
// //     return a;
// // }

// // // Function to calculate the LCM of two numbers
// // int lcm(int a, int b) {
// //     return (a / gcd(a, b)) * b;
// // }

// int main() {
//     int n, m;
//     cin >> n >> m;

//     int index = 2;  // Fibonacci series starts with index 2 (0 and 1 are the first two elements)
//     int prev2 = 0;  // F(0)
//     int prev = 1;   // F(1)
//     int curi = 1;   // To store the current Fibonacci number

//     while (curi < n) {
//         curi = prev2 + prev; // Calculate the next Fibonacci number
//         prev2 = prev;
//         prev = curi;
//         index++;

//         // Check if the Fibonacci number is equal to n
//         if (index % m == 0) {
//             cout << index << "\n";
//             return 0;
//         }
//     }

//     // If no index is found that matches the conditions
//     cout << -1 << endl;
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m,meta;
    cin>>n>>m;
    
    if(n<m)
    {
        cout<<-1;
    }
    else
    {
        if(n%2==0) meta=n/2;
        else meta=(n/2)+1;
        if(meta%m==0)cout<<meta;
        else 
        {
            while(meta%m!=0)
            {
                meta++;
            }
            cout<<meta;
        }
    }
    
    return 0;
}