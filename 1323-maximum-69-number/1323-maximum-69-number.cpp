class Solution {
public:
    int maximum69Number (int num) {
        
        int n = num;
        int PVnextdigit = 1;            // From right to left
        int PVsixchange = 0;            // PV -> Place Value
        
        while(n > 0) 
        {
            int lastDigit = n % 10;
            if(lastDigit == 6) PVsixchange = PVnextdigit;
            PVnextdigit *= 10;
            n /= 10;
        }
        
        // Now we have the place value of leftmost 6 digit
        // We will change the 6 digit with 9 using the formula
        
        num += PVsixchange*3;
        
        return num;
    }
};