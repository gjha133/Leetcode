class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        while(1)
        {
            if(!num1 or !num2) break;
            if(num1 >= num2) num1 -= num2;
            else if(num2 >= num1) num2 -= num1;
            count++;
        }
        
        return count;
    }
};