class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ans = nums[0];
        int cnt = 0;

        for(int i : nums) {
            if(ans == i)
                cnt++;
            else
                cnt--;
            
            if(cnt == 0) {
                ans = i;
                cnt = 1;
            }
        }

        return ans;
    }
};