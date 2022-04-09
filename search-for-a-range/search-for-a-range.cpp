class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos;
        int start = 0;
        int end = nums.size() - 1;
        int first = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)     {first = mid;     end = mid-1;}
            else if(nums[mid] > target) end = mid-1;
            else start = mid + 1;
        }
        pos.push_back(first);
        int last = -1;
        start = 0;
        end = nums.size() - 1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)     {last = mid;     start = mid + 1;}
            else if(nums[mid] > target) end = mid-1;
            else start = mid + 1;
        }
        pos.push_back(last); 
        cout << "Count : " << (last - first + 1);
        return pos;
    }
};