class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        unordered_map<int, int> mp;
        
        for(int& num : arr) mp[num]++;
        
        for(int& num : arr)
        {
            if(mp[num] == 0) continue;
            
            if(mp[2*num] == 0) return false;
            mp[num]--, mp[2*num]--;
        }
        
        return true;
    }
    
    static bool compare(int a, int b)
    {
        return abs(a) < abs(b);
    }
    
};