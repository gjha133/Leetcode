## Recursion:
```
class Solution {
public:
int minimumTotal(vector<vector<int>>& triangle) {
int n = triangle.size();
return minTotal(0, 0, triangle);
}
int minTotal(int i, int j, vector<vector<int>>& triangle)
{
if(i == triangle.size() - 1) return triangle[i][j];
int down = minTotal(i + 1, j, triangle);
int diagonal = minTotal(i + 1, j + 1, triangle);
return triangle[i][j] + min(down, diagonal);
}
};
```
​
## Memoization:
```
class Solution {
public:
int minimumTotal(vector<vector<int>>& triangle) {
int n = triangle.size();
vector<vector<int>> dp (n, vector<int> (n, -1));
return minTotal(0, 0, triangle, dp);
}
int minTotal(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp)
{
if(i == triangle.size() - 1) return triangle[i][j];
if(dp[i][j] != -1) return dp[i][j];
int down = minTotal(i + 1, j, triangle, dp);
int diagonal = minTotal(i + 1, j + 1, triangle, dp);
return dp[i][j] = triangle[i][j] + min(down, diagonal);
}
};
```
​
​