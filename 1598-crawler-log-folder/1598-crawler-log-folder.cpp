class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(auto log : logs)
        {
            if(log == "./")  continue;
            else if(log == "../") count = max(0, count-1);
            else count++;
        }
        
        return count;
    }
};