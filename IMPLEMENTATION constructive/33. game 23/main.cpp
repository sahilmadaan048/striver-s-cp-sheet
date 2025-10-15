// #include<bits/stdc++.h>
// using namespace std;

// vector<pair<int, int>> primeFactors(int n) {
//     vector<pair<int, int>> factors;

//     int count = 0;
//     while (n % 2 == 0) {
//         n /= 2;
//         count++;
//     }
//     if (count > 0) {
//         factors.push_back(make_pair(2, count));
//     }

//     for (int i = 3; i <= sqrt(n); i += 2) {
//         count = 0;
//         while (n % i == 0) {
//             n /= i;
//             count++;
//         }
//         if (count > 0) {
//             factors.push_back(make_pair(i, count));
//         }
//     }

//     if (n > 2) {
//         factors.push_back(make_pair(n, 1));
//     }

//     return factors;
// }

// bool validFactors(int n, vector<pair<int, int>> &factors) {
//     for (auto &pair : factors) {
//         if (pair.first != 2 && pair.first != 3) {
//             return false;
//         }
//     }
//     return true;
// }

// bool isnum(int a, int b, vector<pair<int, int>> &factors) {
//     int c = a / b;
//     if (a % b != 0 || !validFactors(c, factors)) {
//         return false;
//     }
//     return true;
// }

// int main() {
//     int a, b;
//     cin >> a >> b;

//     if (a < b) {
//         cout << "-1" << endl;
//         return 0;
//     }

//     int c = a / b;
//     vector<pair<int, int>> factors = primeFactors(c);

//     if (!isnum(a, b, factors)) {
//         cout << "-1" << endl;
//         return 0;
//     }

//     int count = 0;
//     for (auto &pair : factors) {
//         if (pair.first == 2 || pair.first == 3) {
//             count += pair.second;
//         }
//     }

//     cout << count << endl;
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int a, b;
//     cin >> a >> b;
//     if(a == b){
//         cout << 0 << endl;
//         return 0;
//     }
//     if(a>b){
//         cout << -1 << endl;
//         return 0;
//     }

//     int count = 0;
//     queue<int> q;
//     q.push(a);
//     while(!q.empty()){
//         int size = q.size();
//         count ++;
//         for(int i=0; i<size; i++){
//             int current = q.front();
//             q.pop();

//             int multipliedbytwo = current*2;
//             int multipliedbythree = current*3;

//             if(multipliedbytwo == b || multipliedbythree == b){
//                 cout << count << endl;
//                 return 0;
//             }

//             if(multipliedbytwo < b){
//                 q.push(multipliedbytwo);
//             }
//             if(multipliedbythree < b){
//                 q.push(multipliedbythree);
//             }
//         }

//     }

//     cout << -1 << endl;
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n == m) {
        cout << 0 << endl;
        return 0;
    }

    if (n > m) {
        cout << -1 << endl;
        return 0;
    }

    int count = 0;
    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int size = q.size();
        count++;
        for (int i = 0; i < size; i++) {
            int current = q.front();
            q.pop();

            int multipliedBy2 = current * 2;
            int multipliedBy3 = current * 3;

            if (multipliedBy2 == m || multipliedBy3 == m) {
                cout << count << endl;
                return 0;
            }

            if (multipliedBy2 < m) {
                q.push(multipliedBy2);
            }

            if (multipliedBy3 < m) {
                q.push(multipliedBy3);
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
