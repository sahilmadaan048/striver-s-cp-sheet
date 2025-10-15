#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> parts;
        int factor = 1;
        int count = 0;

        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                parts.push_back(digit * factor);
                count++;
            }
            n /= 10;
            factor *= 10;
        }

        cout << count << endl;
        for (int part : parts) {
            cout << part << " ";
        }
        cout << endl;
    }
    return 0;
    
}
