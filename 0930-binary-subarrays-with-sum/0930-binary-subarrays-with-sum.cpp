class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        int count = 0;
        int sum = 0;

        int left = 0;
        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while(sum > goal && right >= left) {
                sum -= nums[left];
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};