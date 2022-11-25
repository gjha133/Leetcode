class Solution {
public:
    int maximumSwap(int num) {
        string number = to_string(num);
        
        int mxIndex = -1, mxDigit = -1, left = -1, right = -1;
        
        for(int i = number.size() - 1; i >= 0; i--)
        {
            if(number[i] > mxDigit)
            {
                mxDigit = number[i];
                mxIndex = i;
                continue;
            }
            
            if(number[i] < mxDigit)
            {
                left = i;
                right = mxIndex;
            }
        }
        
        if(left == -1) return num;
        
        swap(number[left], number[right]);
        
        return stoi(number);
    }
};