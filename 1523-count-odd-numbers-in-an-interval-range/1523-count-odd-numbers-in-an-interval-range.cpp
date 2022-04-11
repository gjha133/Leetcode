class Solution {
public:
    int countOdds(int low, int high) {
        
        if(isEven(low) and isEven(high)) return ((high-low)/2);
        else return ((high-low)/2) + 1;
    }
    
    
    bool isEven(int num)
    {
        return num % 2 == 0;
    }
};