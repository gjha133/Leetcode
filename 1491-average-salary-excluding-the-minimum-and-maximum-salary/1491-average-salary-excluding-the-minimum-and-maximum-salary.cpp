class Solution {
public:
    double average(vector<int>& salary) {
        double minS = DBL_MAX;
        double maxS = DBL_MIN;
        double sum = 0;
        
        for(int i : salary)
        {
            sum += i;
            if(i > maxS) maxS = i;
            if(i < minS) minS = i;
        }        
        return (sum-minS-maxS)/(salary.size() - 2);
    }
};