class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = size(nums);
        
        for(int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
            if(size(pq) > k) pq.pop();
        }
        
        return pq.top();
    }
};