class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(126, 0);

        for(char ch : s)
            freq[ch]++;

        for(char ch : t)
            freq[ch]--;
        
        int ans = 0;
        for(int it : freq) {
            ans += it < 0 ? -it : 0;
        }

        return ans;
    }
};