class Solution {
public:
    bool isUgly(int num) {        
        vector<int> factors = {2, 3, 5};
        if (num < 1) return false;
        for (int prime: factors) 
            while (num % prime == 0) 
                num /= prime;
        
        return num == 1;
    }
};