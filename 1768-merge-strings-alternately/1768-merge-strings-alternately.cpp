class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string finalWord = "";

        int i = 0, j = 0;
        int n = word1.size();
        int m = word2.size();
        
        while(i < n && j < m) {
            finalWord += word1[i++];
            finalWord += word2[j++];
        }

        while(i < n)
            finalWord += word1[i++];
        
        while(j < m)
            finalWord += word2[j++];
        
        return finalWord;
    }
};