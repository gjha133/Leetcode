class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;  //We are storing index in deque
        
        int n = nums.size();
        
        for(int j=0; j<n; j++)
        {
            // For out of bound element (from the left of array, as we will slide the window)
            if(!dq.empty() and dq.front() == j-k) // If the index at front is out of bound
                dq.pop_front();
            
            while(!dq.empty() and nums[dq.back()] <= nums[j])
                dq.pop_back();
            
            dq.push_back(j);
            if(j >= k-1) ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};