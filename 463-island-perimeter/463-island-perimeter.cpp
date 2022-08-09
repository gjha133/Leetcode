class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int ans = 0;
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(grid[row][col] == 1)
                {
                    ans += 4;
                    
                    if(row > 0 and grid[row-1][col] == 1) ans--;             // Upper is 1
                    if(col > 0 and grid[row][col-1] == 1) ans--;             // Left is 1
                    if(row < rows - 1 and grid[row+1][col] == 1) ans--;      // Down is 1
                    if(col < cols - 1 and grid[row][col+1] == 1) ans--;      // Right is 1
                    
                }
            }
        }
        
        return ans;
        
        
    }
};