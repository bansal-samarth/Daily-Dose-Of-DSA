class Solution {
public:
    // int memo(vector<int>& nums, int idx) {
    //     if(idx >= nums.size())
    //         return 0;

    //     int skip = memo(nums, idx + 1);
        
    //     int take = memo(nums, idx + 2) + nums[idx];

    //     return max(skip, take);
    // }

    int rob(vector<int>& nums) {
        // return memo(nums, 0);

        int n = nums.size();
        vector<int> dp(n+2);
        dp[n] = 0;
        dp[n+1] = 0;
        
        for(int idx = n-1; idx >= 0; idx--) {
            int skip = dp[idx + 1];
        
            int take = dp[idx + 2] + nums[idx];
    
            dp[idx] = max(skip, take);
        }

        return dp[0];
    }
};