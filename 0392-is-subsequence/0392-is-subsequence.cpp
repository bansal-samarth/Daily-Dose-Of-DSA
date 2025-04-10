class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;

        while(i < m && j < n) {

            while(j < n && s[i] != t[j])
                j++;
            
            if(j == n) break;

            i++;
            j++;
        }

        return i == m;
    }
};