#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> temp(n);
        vector<pair<int,int>> temp2;

        for(int i=0; i<n; i++) 
            temp[i] = i+1;

        while(temp.size() != 1){
            int size = temp.size();
            int maxi = (temp[size-1] + temp[size-2]) / 2;
            int ind1 = -1, ind2 = -1;

            for(int i=0; i<size-1; i++){
                for(int j=i+1; j<size; j++){
                    if((temp[i] + temp[j]) / 2 == maxi){
                        ind1 = i;
                        ind2 = j;
                        break;
                    }
                }
                if(ind1 != -1) break;
            }

            temp2.push_back({temp[ind1], temp[ind2]});
            // temp2.push_back({ind1, ind2});
            temp.erase(temp.begin() + ind1);
            temp.erase(temp.begin() + ind2-1);
            temp.push_back(maxi);
            sort(temp.begin(), temp.end());
        }

        cout << temp[0] << endl;
        for(auto &pair : temp2){
            cout << pair.first << " " << pair.second << endl;
        }
    }
    return 0;
}
