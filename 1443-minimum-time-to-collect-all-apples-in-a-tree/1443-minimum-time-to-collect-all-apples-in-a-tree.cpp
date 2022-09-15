class Solution {
public:
    
    vector<vector<int>> adj;
    vector<bool> visited;
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        visited.resize(n, false);
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);            
        }
        
        return 2 * dfs(0, hasApple, 0);
    }
    
    int dfs(int node, vector<bool>& hasApple, int d)
    {
        visited[node] = true;
        int result = d;
        
        for(auto& i : adj[node])
        {
            if(!visited[i])
            {
                int dist = dfs(i, hasApple, d + 1);
                if(dist) result += dist - d;
            }
        }
        
        return (hasApple[node] or result > d) ? result : 0;
    }
};