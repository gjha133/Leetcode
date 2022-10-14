class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> set;
        for(int valx = 1; valx <= bound; valx *= x)
        {
            for(int valy = 1; valx + valy <= bound; valy *= y)
            {
                set.insert(valx + valy);
                if(y == 1) break;
            }
            
            if(x == 1) break;
        }
        
        return vector<int> (begin(set), end(set));
    }
};