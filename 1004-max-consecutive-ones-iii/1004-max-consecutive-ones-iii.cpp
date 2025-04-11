class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeros = 0;
        int maxLen = k;

        int left = 0;
        for(int right = 0; right < n; right++) {

            zeros += nums[right] ? 0 : 1;

            if(zeros > k) {
                while(left <= right && nums[left] == 1)
                    left++;
                
                left++;
                zeros--;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};