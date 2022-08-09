class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int mx = INT_MIN;
        
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(grid[row][col] == 1)
                {
                    mx = max(mx, dfs(grid, row, col));
                }
            }
        }
        
        return mx == INT_MIN? 0 : mx;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        int rows = grid.size(), cols = grid[0].size();
        // Boundary condition
        if(row < 0 or col < 0 or row > rows - 1 or col > cols - 1) return 0;
        
        if(grid[row][col] == 0 or grid[row][col] == 2) return 0;
        
        grid[row][col] = 2;
        
        return 1 + dfs(grid, row + 1, col) + dfs(grid, row - 1, col) + dfs(grid, row, col + 1) + dfs(grid, row, col - 1);
    }
};