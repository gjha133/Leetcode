class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int src = 0, des = 0, zero = 0;
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 0) zero++;
                else if(grid[i][j] == 1)
                {
                    src = i; des = j;
                }
            }
        }
        
        return dfs(src, des, grid, zero);
    }
    
    int dfs(int i, int j, vector<vector<int>>& grid, int zero)
    {
        int m = grid.size(), n = grid[0].size();
        if(i < 0 or i >= m or j < 0 or j >= n) return 0;
        
        if(grid[i][j] == -1) return 0;
        if(grid[i][j] == 2) return zero == -1 ? 1 : 0;        
        
        grid[i][j] = -1;
        zero--;
        
        int total = dfs(i-1, j, grid, zero) + dfs(i+1, j, grid, zero) 
             + dfs(i, j-1, grid, zero) + dfs(i, j+1, grid, zero);
        
        grid[i][j] = 0;
        zero++;
        return total;
    }
};