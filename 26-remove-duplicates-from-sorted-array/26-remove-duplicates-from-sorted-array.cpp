class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int num : nums) s.insert(num);
        
        int i=0; 
        for(int num : s)
        {
            nums[i] = num;
            i++;
        }
        
        return s.size();
    }
};