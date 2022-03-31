```
class Solution {
public:
vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
sort(arr.begin(), arr.end());
vector<vector<int>> output;
int diff = INT_MAX;
int newdiff;
for(int i=1; i<arr.size(); i++)
{
newdiff = abs(arr[i] - arr[i-1]);
if(diff > newdiff)
{
while(!output.empty()) output.pop_back();
vector<int> ans {arr[i-1], arr[i]};
output.push_back(ans);
}
if(diff == newdiff)
{
vector<int> ans {arr[i-1], arr[i]};
output.push_back(ans);
}
diff = min(diff, newdiff);
}
return output;
}
};
​
```