#include <iostream>
#include <vector>
using namespace std;

// Function to generate all boring apartments
vector<int> generateBoringApartments() {
    vector<int> boringApartments;
    for (int digit = 1; digit <= 9; ++digit) {
        int num = digit;
        for (int i = 0; i < 4; ++i) {
            boringApartments.push_back(num);
            num = num * 10 + digit;
        }
    }
    return boringApartments;
}

// Function to count the total number of keypresses
int countKeypresses(int x, const vector<int>& boringApartments) {
    int keypresses = 0;
    for (int apartment : boringApartments) {
        int num = apartment;
        while (num > 0) {
            keypresses++;
            num /= 10;
        }
        if (apartment == x) break;
    }
    return keypresses;
}

int main() {
    int t;
    cin >> t;
    vector<int> boringApartments = generateBoringApartments();
    while (t--) {
        int x;
        cin >> x;
        cout << countKeypresses(x, boringApartments) << endl;
    }
    return 0;
}
