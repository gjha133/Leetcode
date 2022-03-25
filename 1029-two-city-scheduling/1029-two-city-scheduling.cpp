class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int costA = 0;
        vector<int> AtoB;
        for(int i=0; i<costs.size(); i++)
        {
            costA += costs[i][0];
            AtoB.push_back(costs[i][1] - costs[i][0]);
        }
           
        sort(AtoB.begin(), AtoB.end());
        for(int i=0; i<costs.size()/2; i++)  costA += AtoB[i];
        
        return costA;    
    }
};