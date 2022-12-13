//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void markCurrentIsland(int x, int y, int row, int col, vector<vector<char>>& grid)
    {
        // Boundary Case
        if( x<0 or x>=row or y<0 or y>=col or grid[x][y] != '1') return;
        
        grid[x][y] = '2';
        markCurrentIsland(x+1, y, row, col, grid);      // Down
        markCurrentIsland(x-1, y, row, col, grid);      // Up
        markCurrentIsland(x, y+1, row, col, grid);      // Right
        markCurrentIsland(x, y-1, row, col, grid);      // Left
        markCurrentIsland(x+1, y+1, row, col, grid);
        markCurrentIsland(x+1, y-1, row, col, grid);
        markCurrentIsland(x-1, y+1, row, col, grid);
        markCurrentIsland(x-1, y-1, row, col, grid);
    }
    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(!rows) return 0;
        int cols =  grid[0].size();
        int count = 0;
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
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
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends