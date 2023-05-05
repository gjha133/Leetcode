class Solution {
public:
    int maxVowels(string s, int k) {
        int mx = 0, i = 0, j = 0, n = s.size(), count = 0;
        while(j < n) {
            if(isVowel(s[j])) count++;
            // If windows size gets bigger than given length, decrease window length 
            // from beginning and reduce counnt if ith char is a vowel
            if(j - i + 1 > k)
            {
                if(isVowel(s[i])) count--;
                i++;
            }
            if(j - i + 1 == k) mx = max(mx, count);
            j++;
        }
        return mx;
    }
private:
    bool isVowel(char c) { 
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'; 
    }
};