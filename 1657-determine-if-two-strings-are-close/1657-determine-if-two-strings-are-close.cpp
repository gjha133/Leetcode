class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        /*
        if(word1.size() != word2.size()) return false;
        int freq1[26] = {0}, freq2[26] = {0};
        set<char> s1, s2;
        for(int i=0; i<word1.size(); i++)
        {
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
            if( s1.find(word1[i]) == s1.end() ) s1.insert(word1[i]);
            if( s2.find(word2[i]) == s2.end() ) s2.insert(word2[i]);
        }
        
        sort(freq1, freq1 + 26);
        sort(freq2, freq2 + 26);
        
        return s1 == s2 and freq1 == freq2;
        */
        
        if( word1.length() != word2.length() ) return false;
        set<char> s1, s2;
        vector<int> w1(26,0), w2(26,0);
        for(int i=0; i<word1.length(); i++){
            w1[word1[i]-'a']++;
            w2[word2[i]-'a']++;
            s1.insert(word1[i]);
            s2.insert(word2[i]);
        } 
        std::sort(w1.begin(), w1.end());
        std::sort(w2.begin(), w2.end());
        return s1 == s2 && w1 == w2;
        
    }
};