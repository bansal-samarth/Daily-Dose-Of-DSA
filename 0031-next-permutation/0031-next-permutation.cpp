class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int stop = -1;

        int n = nums.size();
        for(int i = n - 1; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {
                stop = i - 1;
                break;
            }
        }

        if(stop != -1) {
            int val = nums[stop];
            
            int i = n - 1;
            for(; i > stop; i--) {
                if(val < nums[i])
                    break;
            }

            swap(nums[stop], nums[i]);
        }

        sort(nums.begin() + stop + 1, nums.end());

        return;
    }
};