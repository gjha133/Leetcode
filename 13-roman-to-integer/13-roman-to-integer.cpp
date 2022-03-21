class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;        // to store the return value
        int temp = 0;       // to store the previous value
        
        for (size_t i = 0; i < s.size(); i++) {
            char curr = s[i];
            int pos = 0;     // to store the current value
            
            switch(curr) {
                case 'I': pos = 1; break;
                case 'V': pos = 5; break;
                case 'X': pos = 10; break;
                case 'L': pos = 50; break;
                case 'C': pos = 100; break;
                case 'D': pos = 500; break;
                case 'M': pos = 1000; break;
                default: return 0;
            }
            
            ret += pos;
            if (temp < pos)
                ret -= temp*2;     // ex: IV, ret = 1 + 5 - 1*2 = 4
            temp = pos;
        }
        
        return ret;
    }
};






/*class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == 'I')
            {
                if(s[i+1] == 'V')               {ans += 4;    i++;}
                else if(s[i+1] == 'X')          {ans += 9;    i++;}
                else ans += 1;
            }
            else if(s[i] == 'V') ans += 5;
            else 
                if(s[i] == 'X')
                {
                    if(s[i+1] == 'L')           {ans += 40;   i++;}
                    else if(s[i+1] == 'C')      {ans += 90;   i++;}
                    else ans += 10;
                }
            else if(s[i] == 'L') ans += 50;
            else 
                if(s[i] == 'C')
                {
                    if(s[i+1] == 'D')           {ans += 400;  i++;}
                    else if(s[i+1] == 'M')      {ans += 900;  i++;}
                    else ans += 100;
                }
            else if(s[i] == 'D') ans += 500;
            else if(s[i] == 'M') ans += 1000;
        }
        
        return ans;
    }
};
*/

