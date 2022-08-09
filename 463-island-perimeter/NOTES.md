}
}
return 0;
}
private:
int dfs(vector<vector<int>> & grid,int i, int j)
{
int rows = grid.size(), cols = grid[0].size();
// Boundary Condition
if(i < 0 or j < 0 or i > rows - 1 or j > cols-1) return 0 ;
// If already visited or encountered water
if(grid[i][j] == 2 or grid[i][j] == 0) return 0;
grid[i][j] = 2;
int ans = 4;
if(i < rows - 1 and grid[i+1][j])ans--;         // checks if top == 1
if(j < cols - 1 and grid[i][j+1])ans--;         //checks if right == 1
if(j > 0 and grid[i][j-1])ans--;                // checks if left == 1
if(i > 0 and grid[i-1][j])ans--;                // checks if bottom == 1
return ans + dfs(grid, i + 1 ,j) + dfs(grid,i-1,j) + dfs(grid,i,j-1) + dfs(grid,i,j+1);
}
};
```