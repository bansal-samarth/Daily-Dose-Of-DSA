class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;

        int maxi = 0;

        int left = 0;
        for(int right = 0; right < s.size(); right++) {
            map[s[right]]++;

            while(left < right && map[s[right]] > 1) {
                map[s[left]]--;
                left++;
            }

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};