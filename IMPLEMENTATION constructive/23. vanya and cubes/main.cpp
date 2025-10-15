#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int level = 0;
    int total_cubes = 0;
    
    while (true) {
        level++;
        int cubes_for_current_level = level * (level + 1) / 2;
        if (total_cubes + cubes_for_current_level > n) {
            break;
        }
        total_cubes += cubes_for_current_level;
    }
    
    cout << (level - 1) << endl;
    return 0;
}
