```
​
## Memoization :
```
class Solution {
public:
int minFallingPathSum(vector<vector<int>>& grid) {
int n = grid.size();
vector<vector<int>> dp (n, vector<int> (n, -1));
int ans = INT_MAX;
for(int j = 0; j<n; j++)
{
ans = min(ans, minSum(n-1, j, grid, dp));
}
return ans;
}
int minSum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
int n = grid.size();
if(j < 0 or j > n-1) return INT_MAX;
if(i == 0) return grid[i][j];
if(dp[i][j] != -1) return dp[i][j];
int ans = INT_MAX;
for(int col = 0; col < n; col++)
{
if(col != j)
{
ans = min(ans, grid[i][j] + minSum(i-1, col, grid, dp));
}
}
return dp[i][j] = ans;
}
};
```
​
## Tabulation :
```
​
```
​
​
​