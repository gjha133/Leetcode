class Solution {
public:
    #define mod 1000000007
    int helper(int dices, int faces, int target, vector<vector<int>>& dp){

        if(dices == 0){
            if(target == 0) return 1;
            return 0;
        } 

        if(target <= 0) return 0;
        
        if(dp[dices][target]!= -1){
            return dp[dices][target];
        }

        size_t count = 0;
        
        for(int i = 1; i <= faces; i++){
               if(i <= target){
                   count += helper(dices-1, faces, target-i, dp);
                   count = count%mod;
               }
           }
        dp[dices][target] = count;
        return dp[dices][target];
    }
   

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(32, vector<int>(1005, -1));
        return helper(n, k, target, dp);
    }
};