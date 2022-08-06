class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans (num_people, 0);
        int person = 0;
        while(candies > 0)
        {
            ans[person % num_people] += person + 1;
            candies -= person + 1;
            person++;
        }
        
        if(candies < 0) ans[ (person - 1) % num_people] += candies;
        
        return ans;
        
    }
};