class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        int prev = INT_MIN;
        bool vis = false;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != prev) {
                prev = nums[i];
                swap(nums[i], nums[j++]);
                vis = false;
            }
            else if(nums[i] == prev && !vis) {
                swap(nums[i], nums[j++]);
                vis = true;
            }
        }

        return j;
    }
};