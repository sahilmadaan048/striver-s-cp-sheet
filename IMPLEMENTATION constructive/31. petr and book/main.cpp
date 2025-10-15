#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> temp(7, 0);
    for(int i = 0; i < 7; i++) cin >> temp[i];
    
    int sum = 0;
    int index = 0;

    while(sum < n){
        for(int i = 0; i < 7; i++){
            sum += temp[i];
            if(sum >= n){
                index = i;
                break;
            }
        }
    }

    cout << (index + 1) << endl;  // output the day number (1-based index)
    return 0;
}
