class Solution {
public:
    void reverseString(vector<char>& s) {
           rev(s, 0, s.size()-1);   
    }
    
    void rev(vector<char> &s, int start, int end)
    {
        if(start >= end) return;
        swap(s[start], s[end]);
        rev(s, ++start, --end);
    }
};