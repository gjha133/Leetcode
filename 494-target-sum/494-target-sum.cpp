class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        int tot_sum = 0;
        for(auto i = 0; i < n; i++)
            tot_sum += arr[i];

        if((tot_sum-target) < 0 || (tot_sum-target)%2) return 0;

        int tar = (tot_sum-target)/2;
        vector<vector<int>> dp(n, vector<int>(tar+1, 0));

        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;

        if(arr[0] != 0 && arr[0] <= tar) dp[0][arr[0]] = 1;

        for(int idx = 1; idx < n; idx++)
        {
            for(int sum = 0; sum <= tar; sum++)
            {
                int not_pick = dp[idx-1][sum];
                int pick = 0;
                if(arr[idx] <= sum) pick = dp[idx-1][sum-arr[idx]];

                dp[idx][sum] = (pick + not_pick);
            }
        }

        return dp[n-1][tar];
    }
    
};