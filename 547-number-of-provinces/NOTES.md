Using adjacency list
class Solution {
public:
int findCircleNum(vector<vector<int>>& mat) {
int V = mat.size();
vector<bool> vis(V, false);
vector<vector<int>> adj(V);
// convert to adj list and find connected components
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
if (mat[i][j] == 1 and i != j)
{
adj[i].push_back(j);
adj[j].push_back(i);
}
}
}
int cnt = 0;
for (int i = 0; i < V; i++) {
if (!vis[i]) {
cnt++;
DFS(i, vis, adj);
}
}
return cnt;
}
void DFS(int src, vector<bool>& vis, vector<vector<int>>& adj) {
vis[src] = true;
for (int u : adj[src]) {
if (!vis[u]) {
DFS(u, vis, adj);
}
}
}
};
​