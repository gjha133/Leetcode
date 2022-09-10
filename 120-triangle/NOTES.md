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