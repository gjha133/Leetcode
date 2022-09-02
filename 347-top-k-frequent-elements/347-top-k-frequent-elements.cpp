class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int num : nums) cnt[num]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for(auto it : cnt)
        {
            minHeap.push({it.second, it.first});
            if(minHeap.size() > k) minHeap.pop();
        }
        
        vector<int> ans;
        while(minHeap.size())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
        
    }
};