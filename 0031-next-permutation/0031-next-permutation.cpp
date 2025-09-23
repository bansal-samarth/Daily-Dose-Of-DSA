class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int change = -1;
        
        int n = nums.size();
        for(int i = n - 1 ; i > 0; i--) {
            if(nums[i] > nums[i - 1]) {
                change = i - 1;
                break;
            }
        }

        if(change != -1) {
            for(int i = n - 1; i >= 0; i--) {
                if(nums[change] < nums[i]) {
                    swap(nums[change], nums[i]);
                }
            }
        }

        sort(nums.begin() + change + 1, nums.end());
    }
};