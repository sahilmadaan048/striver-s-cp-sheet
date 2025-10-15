#include <bits/stdc++.h>
using namespace std;

int swapMin(vector<int>& temp, int i) {
    int count = 0;
    int n = temp.size();
    while (i != n - 1) {
        swap(temp[i], temp[i + 1]);
        count++;
        i++;
    }
    return count;
}

int swapMax(vector<int>& temp, int i) {
    int count = 0;
    while (i != 0) {
        swap(temp[i], temp[i - 1]);
        count++;
        i--;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    // if (n <= 0) {
        // cout << "Array size must be greater than 0." << endl;
        // return 0;
    // }

    vector<int> temp(n);
    for (int i = 0; i < n; i++) cin >> temp[i];

    int count = 0;
    int index = 0;

    // Finding the maximum element
    int ele1 = *max_element(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == ele1) {
            index = i;
            break;
        }
    }
    count += swapMax(temp, index);

    // Finding the minimum element
    int ele2 = *min_element(temp.begin(), temp.end());
    for (int i = n - 1; i >= 0; i--) {
        if (temp[i] == ele2) {
            index = i;
            break;
        }
    }
    count += swapMin(temp, index);

    cout << count << endl;
    return 0;
}