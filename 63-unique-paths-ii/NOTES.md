## Recursion :
```
class Solution {
public:
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
int m = grid.size(), n = grid[0].size();
return countUnique(m-1, n-1, grid);
}
int countUnique(int i, int j, vector<vector<int>>& grid)
{
if(i == 0 and j == 0 and !grid[i][j]) return 1;
if(i < 0 or j < 0) return 0;
if(grid[i][j]) return 0;
int up = countUnique(i-1, j, grid);
int left = countUnique(i, j-1, grid);
return up + left;
}
};
```
​
## Memoization :
```
class Solution {