//////////////// Graphs /////////////////////
/// DFS
#include <bits/stdc++.h>
using namespace  std;

int const MAXN = 1e5 + 5 ;
vector<int> adj[MAXN];
vector<bool> visited(MAXN);
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

/// BFS
