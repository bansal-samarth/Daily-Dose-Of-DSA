class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                int i = mid;
                int j = mid;
                
                while(i > 0 && nums[i - 1] == target) i--;
                while(j < nums.size() - 1 && nums[j + 1] == target) j++;

                return {i, j};
            }

            if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return {-1, -1};
    }
};