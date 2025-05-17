class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;

        int sum = 0;
        int mini = INT_MAX;
        while(right < n) {
            sum += nums[right];

            // if(sum >= target) {
            //     mini = min(mini, right - left + 1);
            // }

            while(sum >= target) {
                mini = min(mini, right - left + 1);
                sum -= nums[left++];
            }

            right++;
        }

        if(mini == INT_MAX)
            return 0;
        
        return mini;
    }
};