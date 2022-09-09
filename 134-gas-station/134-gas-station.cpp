class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0, tank = 0;
        int start = 0;
        
        for(int i = 0; i < gas.size(); i++)
        {
            total_tank += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if(tank < 0)
            {
                tank = 0;
                start = i + 1;
            }
        }
        
        return (total_tank < 0) ? -1 : start;
    }
};