class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        
        //traverse left to right and compare curr value with left side value
        for(int i = 1; i < n; i++)
            if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1]+1;
              
         //traverse right to left and compare curr value with right side value
        for(int i = n-2; i >= 0; i--)
            if(ratings[i] > ratings[i+1]) candies[i] = max(candies[i+1] + 1, candies[i]);
        
        int ans = accumulate(candies.begin(), candies.end(), 0);       
        return ans;            
    }
};