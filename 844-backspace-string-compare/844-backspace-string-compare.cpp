class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int k=0,p=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#') k=max(0,--k);            
            else s[k++]=s[i];
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='#') p=max(0,--p);
            else t[p++]=t[i];
        }
        
        if(k!=p) return false;
        else
        {
            for(int i=0;i<k;i++) if(s[i]!=t[i]) return false;
            return true;
        }
        
    }
};