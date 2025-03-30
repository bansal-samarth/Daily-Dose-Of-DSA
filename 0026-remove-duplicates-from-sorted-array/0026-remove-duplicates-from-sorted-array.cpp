class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        int prev = -111;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != prev) {
                prev = nums[i];
                swap(nums[i], nums[j++]);
            }
        }

        return j;
    }
};