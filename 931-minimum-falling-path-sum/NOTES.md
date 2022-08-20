## Recursion:
```
class Solution {
public:
int minFallingPathSum(vector<vector<int>>& matrix) {
int n = matrix.size();
int ans = INT_MAX;
for(int j = 0; j < n; j++)
{
ans = min(ans, minSum(n-1, j, matrix));
}
return ans;
}
int minSum(int i, int j, vector<vector<int>>& matrix)
{
int n = matrix.size();
if(j < 0 or j >= n) return INT_MAX;
if(i == 0) return matrix[i][j];
int leftD = minSum(i-1, j-1, matrix);
int rightD = minSum(i-1, j+1, matrix);
int up = minSum(i-1, j, matrix);
return min(up, min(leftD, rightD)) + matrix[i][j];
}
};
```
​
Memoization
​