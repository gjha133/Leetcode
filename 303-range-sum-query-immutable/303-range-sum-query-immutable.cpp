class NumArray {
private :
    vector<int> prefixSum;
public:    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.push_back(0);
        for(int num : nums)
        {
            prefixSum.push_back(prefixSum.back() + num);
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */