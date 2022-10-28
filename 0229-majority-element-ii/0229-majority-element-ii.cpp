class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /* Using modified Moore's Voting Algorithm*/
        int num1 = 0, num2 = 0, c1 = 0, c2 = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == num1) c1++;
            else if(nums[i] == num2) c2++;
            else if(c1 == 0) {num1 = nums[i]; c1 = 1;}
            else if(c2 == 0) {num2 = nums[i]; c2 = 1;}
            else {c1--; c2--;}
        }
        
        // Checking if numbers really are in majority
        vector<int> ans;
        c1 = c2 = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] == num1) c1++;
            else if(nums[i] == num2) c2++;
        }
        
        if(c1 > n/3) ans.push_back(num1);
        if(c2 > n/3) ans.push_back(num2);
        return ans;
        
        /* Using Map
        vector<int> ans;
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++) map[nums[i]]++;
        
        for(auto i : map)
        {
            if(i.second > nums.size()/3) ans.push_back(i.first);
        }
        return ans;
        */
    }
};