class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols =  grid[0].size();
        
        int count = 0;       
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    // DFS
                    markCurrentIsland(i, j, rows, cols, grid);
                    count++;
                }
            }
        }
        
        return count;
    }
    
private:
    void markCurrentIsland(int x, int y, int row, int col, vector<vector<char>>& grid)
    {
        // Boundary Case
        if( x < 0 or x >= row or y < 0 or y >= col or grid[x][y] != '1') return;
        
        grid[x][y] = '2';
        markCurrentIsland(x+1, y, row, col, grid);      // Down
        markCurrentIsland(x-1, y, row, col, grid);      // Up
        markCurrentIsland(x, y+1, row, col, grid);      // Right
        markCurrentIsland(x, y-1, row, col, grid);      // Left
    }
    
};