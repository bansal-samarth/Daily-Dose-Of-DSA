class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int maxi = 0;
        for(auto num : nums) {
            if(set.find(num + 1) != set.end())
                continue;
            
            int length = 1; 
            while(set.find(num - length) != set.end()) {
                length++;
            }

            maxi = max(maxi, length);
        }

        return maxi;
    }
};