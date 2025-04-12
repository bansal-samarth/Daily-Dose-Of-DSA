class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n, 0);

        for(int i = n - 2; i >= 0; i--) {
            suff[i] = nums[i+1] + suff[i+1];
        }

        if(suff[0] == 0) return 0;

        int pref = 0;
        for(int i = 1; i < n; i++) {
            pref += nums[i-1];

            if(pref == suff[i]) return i;
        }

        if(pref == 0) return n-1;

        return -1;
    }
};