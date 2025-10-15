 
 //resubmitting it to revise this problem and also the next problem sems a bit tricky
#include <iostream>
using namespace std;
 
void printPattern(int n) {
    int width = 2 * n + 1; // The width of the pattern
 
    // Upper part including the middle row
    for (int i = 0; i <= n; ++i) {
        // Print leading spaces
        for (int j = 0; j < n - i; ++j) {
            cout << "  ";
        }
 
        // Print increasing numbers
        for (int j = 0; j <= i; ++j) {
            if (j != 0) cout << " ";  //we need this condition here for the first row
            cout << j ;
        }
 
        // Print decreasing numbers
        for (int j = i - 1; j >= 0; --j) {
            cout << " " << j;
        }
 
        cout << endl;
    }
 
    // Lower part
    for (int i = n - 1; i >= 0; --i) {
        // Print leading spaces
        for (int j = 0; j < n - i; ++j) {
            cout << "  ";
        }
 
        // Print increasing numbers
        for (int j = 0; j <= i; ++j) {
            if (j != 0) cout << " ";
            cout << j;
        }
 
        // Print decreasing numbers
        for (int j = i - 1; j >= 0; --j) {
            cout << " " << j;
        }
 
        cout << endl;
    }
}
 
int main() {
    int n;
    cin >> n;
    printPattern(n);
    return 0;
}