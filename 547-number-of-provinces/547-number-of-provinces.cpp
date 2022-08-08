class Solution {
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int V = mat.size();
        if(!V) return 0;
        int cnt = 0;
        vector<bool> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) 
            {
                cnt++;
                DFS(i, vis, mat);
            }
        }
        return cnt;
    }
    
    void DFS(int src, vector<bool>& vis, vector<vector<int>>& mat) {
        vis[src] = true;
        for (int j=0; j<mat.size(); j++) 
        {
            if (!vis[j] and mat[src][j]) 
                DFS(j, vis, mat);
        }
    }
};