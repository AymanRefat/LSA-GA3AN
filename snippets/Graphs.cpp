#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+5;
/*******************************Graph Theory**************************************/

//DFS
bool vis[N];
vector<int>adj[N];
void dfs(int node)
{
    vis[node] = 1;
    for(auto& child : adj[node])
        if(!vis[child])
            dfs(child);
}

//BFS
vector<int>dis(N,-1);
void bfs(int node)
{
    queue<int>q;
    q.push(node);
    dis[node] = 0;
    while(q.size())
    {
        int cur = q.front();
        q.pop();
        for(auto& child : adj[cur])
        {
            if(dis[child] == -1)
                q.push(child) , dis[child] = dis[cur]+1;
        }
    }
}

//detecting cycle and extracting its nodes
int head , tail;
set<int>cycle;
void dfs(int node , int par)
{
    if(cycle.size())return;
    vis[node] = 1;
    for(auto& child : adj[node])
    {
        if(!vis[child])
            dfs(child,node);
        else if(child != par)
        {
            head = child,tail = node;
            cycle.insert(head);
            cycle.insert(tail);
            return;
        }
        if(cycle.size())
            return;
    }
}

//printing path
int node = n;
vector<int> path;
path.pb(node);
while(parent[node] != -1)
{
path.pb(parent[node]);
node = parent[node];
}
if(path.size())
reverse(all(path));
print(path);


//Dijkstra
vector<pair<int,int>>graph[N];//{node,cost}
vector<int>ans(N,1e18);
void dijkstra(pair<int,int>source)//source -> {cost,node}
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push(source);
    ans[source.second] = 0;
    while(pq.size())
    {
        pair<int,int>cur = pq.top();
        pq.pop();
        int node = cur.second , cost = cur.first;
        if(ans[node] < cost)
            continue;
        for(auto& [child,c] : graph[node])
        {
            if(ans[child] > cost+c)
            {
                ans[child] = cost+c;
                pq.push({ans[child],child});
            }
        }
    }
}

//Lowest Common Ancestor (LCA)
ll n,q,lvl[N],anc[N][23],Log = 23;
void buildAncestors(ll node , ll par)
{
    lvl[node] = lvl[par]+1;
    anc[node][0] = par;
    for(ll i = 1 ; i < Log ; ++i)
    {
        ll p = anc[node][i-1];
        anc[node][i] = anc[p][i-1];
    }
    for(auto& child : adj[node])
    {
        if(child != par)
            buildAncestors(child,node);
    }
}

ll kthAncestor(ll node , ll k)
{
    for(ll i = Log-1 ; i >= 0 ; --i)
    {
        if((k>>i)&1)
        {
            node = anc[node][i];
        }
    }
    return node;
}

ll LCA(ll u, ll v)
{
    if(lvl[u] < lvl[v])
        swap(u,v);
    u = kthAncestor(u,lvl[u]-lvl[v]);
    if(u==v)
        return u;
    for(int i = Log-1 ; i >= 0 ; --i)
    {
        if(anc[u][i] != anc[v][i])
        {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[v][0];
}

ll dist(ll u , ll v)
{
    ll lca = LCA(u,v);
    return lvl[u]+lvl[v]-2*lvl[lca];
}

//finding all bridges in graph
void dfs(ll node , vector<ll>&disc, vector<ll>&low , vector<ll>&parent , vector<pair<ll,ll>>&bridges)
{
    static ll time = 0;
    disc[node] = low[node] = time;
    time++;
    for(auto& child : adj[node])
    {
        if(disc[child] == -1)
        {
            parent[child] = node;
            dfs(child,disc,low,parent,bridges);
            low[node] = min(low[child],low[node]);
            if(low[child] > disc[node])
                bridges.push_back({node,child});
        }
        else if(child != parent[node])
        {
            low[node] = min(low[node],disc[child]);
        }
    }
}


vector<pair<ll,ll>> findBridges(ll n)
{
    vector<ll>disc(N,-1) , low(N,-1) , parent(N,-1);
    vector<pair<ll,ll>>bridges;
    for(int i = 1 ; i <= n ; ++i)
        if(disc[i] == -1)
            dfs(i,disc,low,parent,bridges);
    return bridges;
}

//BellmanFord algorithm (longest & shortest path in directed , weighted graph)
const int N = 100;
int n, m;
vector<pair<int, int>> adj[N];
void bellmanFord()
{
    // Shortest Path in A directed Weighted Graph

    vector<ll> dis(n + 1, -inf);
    dis[1] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (auto &[v, c] : adj[j])
            {
                if (dis[j] != dis[v] < inf and dis[j] + c) // if Longest Path ( > )
                    dis[v] = dis[j] + c;
            }
        }
    }

    bool negativeCycle = false;
    for (int i = 1; i <= n; ++i)
    {
        for (auto &[v, c] : adj[i])
        {
            if (dis[i] != -inf and dis[v] < dis[i] + c) // if Positive Cycle ( > )
            {
                negativeCycle = true;
            }
        }
    }
}