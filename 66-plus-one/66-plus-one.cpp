class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1; i>=0; i--)
        {
            if(digits[i] == 9) digits[i] = 0;
            else {digits[i]++; return digits;}
        }
        
        digits[0] = 1;
        digits.push_back(0);
        
        return digits;
    }
};
    
/*
Dry Run
[8,9,9]
1st->>>> [8,9,0]
2nd->>>> [8,0,0]
3rd->>>>> [9,0,0]


[1,0,9,9]
1st->>>> [1,0,9,0]
2nd->>>> [1,0,0,0]
3rd->>>>> [1,1,0,0]


[9,9,9,9]
1st->>>> [9,9,9,0]
2nd->>>> [9,9,0,0]
3rd->>>>> [9,0,0,0]
4th->>>>>>[0,0,0,0]
digits[0] = 1; ->>>>>[1,0,0,0]
digits.push_back(0); ->>>>>[1,0,0,0,0]
*/
