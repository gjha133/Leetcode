class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        if(nums.size() == 1 and nums[0] == "1") return "0";
        if(nums.size() == 1 and nums[0] == "0") return "1";
        unordered_map<string, int> mp;
        for(auto s : nums) mp[s]++;
        int n = nums[0].size();
        queue<string> q;
        q.push("0");
        q.push("1");
        
        string ans = "";
        
        while(1)
        {
            auto cur = q.front();
            q.pop();
            
            if(mp.count(cur) == 0 and cur.size() == n) return cur;            
            q.push(cur + "0");
            q.push(cur + "1");
        }
        
        return "";
    }
};