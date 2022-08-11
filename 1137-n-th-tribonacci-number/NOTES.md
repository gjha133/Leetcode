{
dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
}
return dp[n];
}
};
```
​
Using Variables : O(1) Space
```
class Solution {
public:
int tribonacci(int n) {
if(n <= 1) return n;
int prev3 = 0, prev2 = 1, prev1 = 1;
for(int i = 3; i <= n; i++)
{
int curr = prev1 + prev2 + prev3;
prev3 = prev2;
prev2 = prev1;
prev1 = curr;
}
return prev1;
}
};
```