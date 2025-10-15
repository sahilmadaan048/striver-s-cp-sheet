// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     int a = -1, b = -1;

//     for (int i = 0; i * 7 <= n; i++) {
//         if ((n - i * 7) % 4 == 0) { //it's a integer value 
//             a = (n - i * 7) / 4;
//             b = i;
//             break;
//         }
//     }

//     if (a == -1 && b == -1) {
//         cout << -1 << endl; // No solution
//     } else {
//         cout << string(a, '4') + string(b, '7') << endl;
//     }

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int minLength = INT_MAX;
    string result = "-1";

    // Try different numbers of '7's from 0 up to n/7
    for (int b = 0; b * 7 <= n; ++b) {
        int remaining_sum = n - b * 7;
        if (remaining_sum % 4 == 0) {  // Check if the remaining sum can be filled with '4's
            int a = remaining_sum / 4;
            string candidate = string(a, '4') + string(b, '7');
            if (candidate.length() < minLength) {
                minLength = candidate.length();
                result = candidate;
            }
        }
    }

    cout << result << endl;
    return 0;
}
