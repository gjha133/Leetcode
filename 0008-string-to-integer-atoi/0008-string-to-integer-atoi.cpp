class Solution {
public:
    int myAtoi(string s) {
        int res=0;
        int i=0;
        int sign=1;
		
        while(i<s.size() and s[i]==' ') i++;   //ignore leading white space
        
        if(s[i] =='-' or s[i] == '+')          //check if number positve or negative
        {
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }
        // now iterate across digits if any
		// should only be in range 0-9
        while(i < s.length() and isdigit(s[i]))  //traverse string till nondigit not found or string ends
        {
            int digit = (s[i]-'0')*sign;
            if(sign == 1  and  (res>INT_MAX/10 or (res==INT_MAX/10  and  digit>INT_MAX%10))) return INT_MAX; //check for overflow
            if(sign == -1 and (res<INT_MIN/10 or (res==INT_MIN/10  and  digit<INT_MIN%10))) return INT_MIN;   //check for underflow
            
            res = res*10 + digit; // update res
            i++;
        }
    
    return res;
    }
};