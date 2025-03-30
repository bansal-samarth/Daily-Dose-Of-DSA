class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt = 1;
        int num = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == num) {
                cnt++;
            }
            else if(cnt > 1) {
                cnt--;
            }
            else {
                num = nums[i];
            }
        }

        return num;
    }
};