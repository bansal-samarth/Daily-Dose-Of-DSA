class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int val = nums[mid];

            if(val == target)
                return mid;
            
            if(val <= nums[high]) {
                if(val < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            } else {
                if(nums[low] <= target && target < val)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return -1;
    }
};