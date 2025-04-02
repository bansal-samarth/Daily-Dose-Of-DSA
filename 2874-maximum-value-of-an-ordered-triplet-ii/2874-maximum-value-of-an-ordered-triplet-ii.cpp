class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> k(n, 0);
        k[n-1] = nums.back();
        for(int x = n - 2; x >= 0; x--)
            k[x] = max(nums[x+1], k[x+1]);
        
        vector<int> i(n, 0);
        i[0] = nums.front();
        for(int x = 1; x < n; x++)
            i[x] = max(nums[x-1], i[x-1]);

        long long maxi = 0;
        for(int j = 1; j < n-1; j++) {
            maxi = max(maxi,(long long) (i[j] - nums[j]) * k[j]);
        }

        return maxi;
    }
};