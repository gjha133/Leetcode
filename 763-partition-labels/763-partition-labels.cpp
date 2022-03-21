class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> map;
        // Filling max range of every char
        for(int i=0; i<s.size(); i++) map[s[i]] = i;
        
        vector<int> ans;
        int prev = -1, maxi = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            maxi = max(maxi, map[s[i]]);
            // Partitioning when iterator reaches to maxi
            if(maxi == i)
            {
                ans.push_back(maxi - prev);
                // Making prev = maxi so that we can count the length 
                prev = maxi;
            }
        }
        
        return ans;
        
        /*
        https://leetcode.com/problems/partition-labels/discuss/1868842/JavaC%2B%2B-VISUALLY-EXPLAINEDDDDD!!
        */
    }
};