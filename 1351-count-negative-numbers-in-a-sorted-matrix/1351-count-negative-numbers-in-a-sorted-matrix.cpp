class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int col = m - 1, row = 0, ans = 0;
        
        while(row < n)
        {
            while(col >= 0 and grid[row][col] < 0) col--;
            ans += m - col - 1;
            row++;
        }
        
        return ans;
    }
};