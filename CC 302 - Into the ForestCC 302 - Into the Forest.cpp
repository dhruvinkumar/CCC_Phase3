#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int vis[1001];

int dfs(int u) {
    vis[u] = 1;
    int size = 1;
    for(int v : adj[u]) {
        if(!vis[v]) {
            size += dfs(v);
        }
    }
    return size;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int num_trees = 0;
    int max_size = 0;
    int min_size = INT_MAX;
    
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            num_trees++;
            int size = dfs(i);
            max_size = max(max_size, size);
            min_size = min(min_size, size);
        }
    }
    
    cout << max_size << " " << min_size << " " << num_trees << endl;
    
    return 0;
}
