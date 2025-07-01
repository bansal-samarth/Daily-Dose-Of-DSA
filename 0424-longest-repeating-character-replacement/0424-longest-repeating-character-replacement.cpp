class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        unordered_map<char, int> map;

        int maxFreq = 0;
        int ans = 0;
        int left = 0;
        for(int right = 0; right < n; right++) {
            maxFreq = max(maxFreq, ++map[s[right]]);

            if(right - left + 1 - maxFreq > k) {
                map[s[left++]]--;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};