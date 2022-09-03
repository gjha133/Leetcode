class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int nfirst = firstList.size(), nsecond = secondList.size();
        int i = 0, j = 0;
        
        while(i < nfirst and j < nsecond)
        {
            int front = max(firstList[i][0], secondList[j][0]);
            int back = min(firstList[i][1], secondList[j][1]);
            
            if(back - front >= 0) ans.push_back({front, back});
            
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        
        return ans;
    }
};