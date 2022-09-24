class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp (dungeon.size(), vector<int> (dungeon[0].size(), -1));
        return minHP(dungeon, 0, 0, dp);
    }
    
    int minHP(vector<vector<int>>& dungeon, int i, int j, vector<vector<int>>& dp)
    {
        int m = dungeon.size(), n = dungeon[0].size();
        
        if(i == m or j == n) return INT_MAX;
        
        if(i == m-1 and j == n-1) 
        {
            if(dungeon[i][j] <= 0) return 1 - dungeon[i][j];
            return 1;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = minHP(dungeon, i+1, j, dp);
        int right = minHP(dungeon, i, j+1, dp);
        
        // dungeon[i][j], when value is negative, then it will be added to cost, but if its positive then we will subtract from health. 
		// And after operation if the value becomes negative that means we have enough health to move from (i, j) -> (m-1, n-1). So, we return 1.
        
        int minHealth = min(down, right) - dungeon[i][j];
        
        if(minHealth <= 0) return dp[i][j] = 1;
        
        return dp[i][j] = minHealth;       
    }
};