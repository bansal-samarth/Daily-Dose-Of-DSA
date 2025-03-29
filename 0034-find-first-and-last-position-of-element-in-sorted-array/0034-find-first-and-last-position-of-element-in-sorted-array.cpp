class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                int i = mid-1, j = mid+1;
                while(i >= 0 && nums[i] == target) i--;
                while(j < n && nums[j] == target) j++;

                return {i+1, j-1};
            }

            if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return {-1, -1};
    }
};