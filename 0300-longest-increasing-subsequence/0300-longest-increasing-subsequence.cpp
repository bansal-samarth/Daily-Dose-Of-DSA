class Solution {
public:
    int solve(vector<int>& nums, int idx, int prev) {
        if(idx == nums.size())
            return 0;

        int skip = solve(nums, idx + 1, prev);

        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev])
            take = solve(nums, idx + 1, idx) + 1;

        return max(skip, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        // return solve(nums, 0, -1);

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = 0; i < n+1; i++)
            dp[n][i] = 0;

        for(int idx = n-1; idx >= 0; idx--) {
            for(int prev = idx-1; prev >= -1; prev--) {
                int skip = dp[idx + 1][prev+1];
        
                int take = 0;
                if(prev == -1 || nums[idx] > nums[prev])
                    take = dp[idx + 1][idx+1] + 1;
        
                dp[idx][prev+1] = max(skip, take);
            }
        }

        return dp[0][-1+1];
    }
};