class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        for(int candy : candies) mx = max(candy, mx);
        vector<bool> ans (candies.size());
        for(int i = 0; i < candies.size(); i++) {
            if(extraCandies + candies[i] >= mx) ans[i] = true;
            else ans[i] = false;
        }
        
        return ans;
    }
};