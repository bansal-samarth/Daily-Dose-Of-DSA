class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;

        vector<int> freq(126, 0);
        int maxi = 1;

        int left = 0;
        for(int i = 0; i < s.size(); i++) {
            freq[s[i]]++;

            while(freq[s[i]] > 1) {
                --freq[s[left++]];
            }

            maxi = max(maxi, i - left + 1);
        }

        return maxi;
    }
};