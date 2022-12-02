class Solution {
public:
    int minimumSwap(string s1, string s2) {
        
        //if the both characters at some index are same
        //skip them
        //if they differ then calculate x and y count in any string
        
        int x = 0, y = 0;
        for(int i = 0; i < s1.length(); i++)
        {
            if(s1[i] != s2[i]) 
                (s1[i] == 'x') ? x++ : y++; 
        }
        
        //if both x and y character's sum is odd we cant make them equal
        if((x+y)&1) return -1;
        
        int ans = (x+y)/2;
        
        if (x&1)
        {
            //if number of x are odd we need one more swap to make them equal
            ans++;
        }
        
        return ans;
    }
};