class Solution {
public:
    bool possible(vector<int>& nums, int idx, int target, vector<vector<int>>& memo) {
        if (target == 0)
            return true;
        if (target < 0 || idx >= nums.size())
            return false;
        if (memo[idx][target] != -1)
            return memo[idx][target];
        
        bool skip = possible(nums, idx + 1, target, memo);
        bool take = possible(nums, idx + 1, target - nums[idx], memo);
        
        memo[idx][target] = skip || take;
        return memo[idx][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
        return possible(nums, 0, target, memo);
    }
};
