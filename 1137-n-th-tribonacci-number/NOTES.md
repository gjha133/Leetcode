{
if(n == 0) return 0;
if(n == 1 or n == 2) return 1;
if(dp[n] != -1) return dp[n];
return dp[n] = memoize(n - 1, dp) + memoize(n - 2, dp) + memoize(n - 3, dp);
}
};
```
​
Tabulation :
```
class Solution {
public:
int tribonacci(int n) {
if(n <= 1) return n;
vector<int> dp(n+1);
dp[0] = 0, dp[1] = dp[2] = 1;
for(int i = 3; i <= n; i++)
{
dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
}
return dp[n];
}
};
```
​
​