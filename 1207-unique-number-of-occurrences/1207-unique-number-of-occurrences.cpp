class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      unordered_map<int, int> mp;
      unordered_set<int> set;
      for (auto n : arr) mp[n]++;
      for (auto& p : mp) set.insert(p.second);
      return mp.size() == set.size();
}
};