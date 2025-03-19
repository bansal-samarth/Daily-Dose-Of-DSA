class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> map;

        int left = 0;
        int maxi = 0;
        int ans = 1;
        for(int right = 0; right < s.size(); right++) {

            map[s[right]]++;

            maxi = max(maxi, map[s[right]]);

            while(left <= right && (right - left + 1) - maxi > k) {
                map[s[left]]--;

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};