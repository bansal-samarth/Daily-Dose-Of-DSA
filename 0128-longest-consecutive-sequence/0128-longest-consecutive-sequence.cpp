class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

        unordered_set<int> map(nums.begin(), nums.end());

        int maxi = 1;
        for(int i : map) {

            if(map.find(i + 1) != map.end())
                continue;
            
            int val = i;
            while(map.find(val-1) != map.end()) {
                val--;
            }

            maxi = max(maxi, i - val + 1);
        }

        return maxi;
    }
};