class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*Moore's Voting Algorithm
        [      2         ,        2       ,         1       ,         1         ,        1            ,      2         ,       2         ]
          count = 1          count = 2        count = 1          count = 0           count = 1            count = 0         count = 1
          num = 2               num = 2         num = 2           num = 2             num = 1               num = 1          num = 2
        
        Return 2 as answer.
        When count BECOMES 0 at that time the majority and minority element cancel each other out.
        2-2-1-1 [Both 2 and 1 are appearing 2 times]
        1-2 [Both 1 time]
        */    
        
        
        int count = 0;
        int num = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(count == 0) num = nums[i];
            if(nums[i] == num) count++;
            else count--;
        }
        
        return num;
    }
};