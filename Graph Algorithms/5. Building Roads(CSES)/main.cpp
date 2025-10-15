#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5; // Assumes n <= 100000
vector<int> graph[MAX_N];
bool vis[MAX_N];

void dfs(int node) {
    vis[node] = true;
    for (int neighbor : graph[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    // Reading roads
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> components;
    
    // Find connected components using DFS
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            components.push_back(i); // Each unvisited node starts a new component
            dfs(i);
        }
    }
    
    // Output the number of roads required
    int k = components.size() - 1;
    cout << k << endl;
    
    // Connect the components
    for (int i = 0; i < k; i++) {
        cout << components[i] << " " << components[i + 1] << endl;
    }
    
    return 0;
}
