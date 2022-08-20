​
## Memoization:
```
class Solution {
public:
int minFallingPathSum(vector<vector<int>>& matrix) {
int n = matrix.size();
vector<vector<int>> dp (n, vector<int> (n, -1));
int ans = INT_MAX;
for(int j = 0; j < n; j++)
{
ans = min(ans, minSum(n-1, j, matrix, dp));
}
return ans;
}
int minSum(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp)
{
int n = matrix.size();
if(j < 0 or j >= n) return INT_MAX;
if(i == 0) return matrix[i][j];
if(dp[i][j] != -1) return dp[i][j];
int leftD = minSum(i-1, j-1, matrix, dp);
int rightD = minSum(i-1, j+1, matrix, dp);
int up = minSum(i-1, j, matrix, dp);
return dp[i][j] = min(up, min(leftD, rightD)) + matrix[i][j];
}
};
```
​
## Tabulation:
​
​
​
​