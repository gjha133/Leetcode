class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int V = graph.size();

        // 0: uncolored; 1: color A; -1: color B
        vector<int> color(V); 

        queue<int> q; //For BFS    

        for (int i = 0; i < V; i++) 
        {
            if (color[i]) continue; // skip already colored nodes

            // BFS with seed node i to color neighbors with opposite color
            color[i] = 1; // color seed i to be A (doesn't matter A or B) 
            for (q.push(i); !q.empty(); q.pop()) 
            {
                int node = q.front();
                for (int neighbor : graph[node]) 
                {
                    if (!color[neighbor]) // if uncolored, color with opposite color
                    { 
                        color[neighbor] = -color[node]; 
                        q.push(neighbor); 
                    } 		  
                    else
                    {
                        if (color[neighbor] == color[node])    // if already colored with same color, can't be bipartite!
                            return false;       
                    }

                }        
            }
        }
    
        return true;
  }
};