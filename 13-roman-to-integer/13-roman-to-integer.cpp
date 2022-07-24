class Solution {
public:
    int romanToInt(string str) {
        int ans = 0;        // To store final ans
        int prev = 0;       // To store value of last char
        
        for(int i=0; i<str.size(); i++)
        {
            char curr = str[i];
            int val = 0;
            
            switch(curr)
            {
                case 'I': val = 1; break;
                case 'V': val = 5; break;
                case 'X': val = 10; break;
                case 'L': val = 50; break;
                case 'C': val = 100; break;
                case 'D': val = 500; break;
                case 'M': val = 1000; break;
                default: return 0;
            }
            
            ans += val;
            if(prev < val) ans -= prev*2;
            prev = val;
        }
        
        return ans;
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

