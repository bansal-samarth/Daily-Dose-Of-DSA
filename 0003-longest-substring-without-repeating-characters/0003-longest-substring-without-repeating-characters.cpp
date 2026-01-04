class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> freq(128, 0);

        int left = 0;
        int maxi = 0;
        for(int right = 0; right < s.size(); right++) {
            freq[s[right]]++;

            while(left < right && freq[s[right]] > 1) {
                --freq[s[left++]];
            }

            maxi = max(maxi, right - left + 1);
        } 

        return maxi;
    }
};