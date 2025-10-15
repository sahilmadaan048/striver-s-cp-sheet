// #include<bits/stdc++.h>
// using namespace std;

// void dfs(int node,int cats_count,int count_res,int m,vector<vector<int>>&graph, vector<int>&vis, vector<int>&cats){
// 	vis[node]=1;
// 	if(cats[node]==1) cats_count++;
// 	else cats_count=0;
// 	if(cats_count>m) return;
// 	bool flag=true;
// 	for(auto it: graph[node]){
// 		if(!vis[it]){
// 			flag=false;
// 			dfs(it, cats_count, count_res,m, graph,vis,cats);
// 		}
// 	}
// 	if(flag) count_res++;
// }

// int main(){
// 	int n,m;
// 	cin>>n>>m;
// 	vector<int> cats(n+1);
// 	for(int i=1; i<=n; i++) cin>>cats[i];
// 	vector<int> vis(n+1, 0);
// 	vector<vector<int>> graph(n);
// 	for(int i=0;i<n-1;i++){
// 		int u,v;
// 		cin>>u>>v;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	int count_res=0;
// 	int cats_count=0;
// 	dfs(1,cats_count,count_res,m,graph,vis,cats);
// 	cout<<count_res<<endl;
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
 
int n, m;
const int N = 1e5 + 10;
vector<int> cats(N, 0);
vector<int> g[N];
vector<int> visited(N, 0);
int count_res = 0;
 
// bool isleaf(int node){
// 	return (g[node].size == 1 && node != 1);
// }
 
// bool is_further_traverse(int node, int cats_count){
// 	return (cats_count<=m);
// }
 
void dfs(int node, int cats_count){
	visited[node]=1;
 
	if(cats[node] == 1) cats_count++;
	else cats_count = 0 ;
 
	if(cats_count > m) return;
	
	bool leaf = true;
 
	for(auto neighbor: g[node]){
		if(!visited[neighbor]){
			leaf = false;
			dfs(neighbor, cats_count);
		}
	}
	if(leaf) count_res++;
}
 
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);  // Add edge both ways since it's an undirected tree
    }
 
    dfs(1, 0);
    cout << count_res << endl;
    return 0;
}