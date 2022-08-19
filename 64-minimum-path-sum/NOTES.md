## Recursion :
```
class Solution {
public:
int minPathSum(vector<vector<int>>& grid) {
int m = grid.size(), n = grid[0].size();
return minSum(m-1, n-1, grid);
}
int minSum(int i, int j, vector<vector<int>> &grid)
{
if(i == 0 and j == 0) return grid[i][j];
if(i < 0 or j < 0) return INT_MAX;
int up = minSum(i-1, j, grid);
int left = minSum(i, j-1, grid);
return grid[i][j] + min(up, left);
}
};
```
​