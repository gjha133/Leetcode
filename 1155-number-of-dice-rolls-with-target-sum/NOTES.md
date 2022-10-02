```
class Solution {
public:
#define M 1000000007
int numRollsToTarget(int n, int k, int target) {
if(n == 0)
{
if(target == 0) return 1;
return 0;
}
int count = 0;
for(int num = 1; num <= k; num++)
{
count += numRollsToTarget(n-1, num, target-num);
}
return count % M;
}
};
```