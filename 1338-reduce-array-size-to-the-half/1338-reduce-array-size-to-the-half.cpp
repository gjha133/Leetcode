class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        priority_queue<int> q;
        
        int mn = 0, removed = 0, n = arr.size();
        
        for(int num : arr) mp[num]++;
        for(auto it : mp) q.push(it.second);
        
        while(removed < n/2)
        {
            removed += q.top();
            q.pop();
            mn++;
        }
        
        return mn;
    }
};