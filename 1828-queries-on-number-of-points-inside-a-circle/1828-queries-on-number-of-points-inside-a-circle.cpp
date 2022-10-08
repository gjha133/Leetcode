class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int query = 0; query < queries.size(); query++)
        {
            int count = 0;
            int x = queries[query][0], y = queries[query][1], r = queries[query][2];
            for(int point = 0; point < points.size(); point++)
            {
                if( (x - points[point][0])*(x - points[point][0]) + (y - points[point][1])*(y - points[point][1]) <= r*r)
                    count++;
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};