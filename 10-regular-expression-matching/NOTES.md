## Recursion:
```
class Solution {
public:
bool isMatch(string s, string p) {
int n = s.size(), m = p.size();
return f(n-1, m-1, s, p);
}
int f(int i, int j, string& s, string& p)
{
// Base Case
if(i < 0 and j < 0) return true;   // If s and p are both travelled completely
if(j < 0 and i >= 0) return false; // If only p is travelled completely
if(i < 0 and j >= 0)               // If only s is travelled completely
{
// Consider case : s = "a", p = "x*x*a". After 1st rec call, s gets exhausted then
//  "x*x*"" can be considered empty only if there is a * there.
while(j >= 0)
{
if(p[j] == '*') j -= 2;
else return false;
}
return true;
}