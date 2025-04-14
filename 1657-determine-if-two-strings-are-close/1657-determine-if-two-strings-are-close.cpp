class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        if(n1 != n2) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(char ch : word1)
            freq1[ch - 'a']++;

        for(char ch : word2)
            freq2[ch - 'a']++;
        
        for(int i = 0; i < 26; i++) {
            if((freq1[i] && !freq2[i]) || (!freq1[i] && freq2[i]))
                return false;
        }
        
        ranges::sort(freq1);
        ranges::sort(freq2);

        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i])
                return false;
        }

        return true;
    }
};