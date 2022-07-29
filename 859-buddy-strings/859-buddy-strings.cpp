class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n1 = size(s), n2 = size(goal);
        
        if(n1 != n2) return false;
        if(n1 == 1 or !n1) return false;
        
        // If strings are same, we check for duplicate element
        // aabcdd . We can swap a<->a or d<->d
        if( s == goal )
        {
            set<char> set(s.begin(), s.end());
            if(size(set) != n1) return true;
            return false;
        }
        
        // We will find the count of differences between the strings
        int one = -1, two = -1, difference = 0;
        for(int i=0; i<n1; i++)
        {
            if(s[i] != goal[i])
            {
                difference++;
                if(one == -1) one = i; 
                else if(two == -1) two = i;
                
                if(difference > 2) return false;
            }
        }
        
        if(difference == 2)
        {
            if(s[one] == goal[two] and s[two] == goal[one]) return true;
        }
        
        return false;
        
        
        
    }
};