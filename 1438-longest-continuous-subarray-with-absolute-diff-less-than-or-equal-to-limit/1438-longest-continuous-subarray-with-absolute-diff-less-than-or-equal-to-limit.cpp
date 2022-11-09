class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> mn, mx;
        int j = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            // For maintaining mx deque
            while(!mx.empty() and nums[i] > mx.back()) 
                mx.pop_back();
            
            mx.push_back(nums[i]);
            
            // For maintaining mn deque
            while(!mn.empty() and nums[i] < mn.back())
                mn.pop_back();
            
            mn.push_back(nums[i]);
            
            // If the diff btw max and min > limit then we remove the starting element of the window
            while(mx.front() - mn.front() > limit){
                if(nums[j] == mx.front()) mx.pop_front();
                if(nums[j] == mn.front()) mn.pop_front();
                j++;
            }
            
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};