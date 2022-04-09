class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int x : nums) cnt[x] += 1;

        vector<pair<int, int>> maxHeap;
        for (auto [num, freq] : cnt) maxHeap.emplace_back(freq, num);
        make_heap(maxHeap.begin(), maxHeap.end()); // default is maxHeap

        vector<int> ans;
        while (k-- > 0) {
            auto [_, num] = maxHeap[0];
            pop_heap(maxHeap.begin(), maxHeap.end());
            maxHeap.pop_back(); // delete the unused last element

            ans.push_back(num);
        }
        return ans;
    }
};