class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int mx = 0;
        int rows = grid.size(), cols = grid[0].size();
        
        for(int i = 0; i < rows-2; i++)
        {
            int sum = 0;
            for(int j = 0; j < cols-2; j++)
            {
                sum = grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                mx = max(mx, sum);
            }
        }
        
        return mx;
    }
};