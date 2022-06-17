class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int num : nums) s.insert(num);
        
        int i=0; 
        for(auto itr = s.begin(); itr != s.end(); itr++)
        {
            nums[i] = *itr;
            i++;
        }
        
        return s.size();
    }
};