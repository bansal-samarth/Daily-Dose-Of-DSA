class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0;
        int maxi = INT_MIN;

        for(int num : nums) {
            sum += num;

            maxi = max(sum, maxi);

            sum = sum < 0 ? 0 : sum;
        }

        return maxi;
    }
};