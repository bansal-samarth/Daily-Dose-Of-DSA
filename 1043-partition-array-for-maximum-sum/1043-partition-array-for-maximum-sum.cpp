class Solution {
public:
    int dp[501];
    int solve(int idx, vector<int>& arr, int k) {
        if(idx == arr.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];
        
        int len = 0;
        int maxi = arr[idx];

        int ans = 0;
        for(int i = idx; i < min(idx + k, (int)arr.size()); i++) {
            maxi = max(maxi, arr[i]);
            len++;

            ans = max(ans, solve(i+1, arr, k) + (maxi * len));
        }

        return dp[idx] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, arr, k);
    }
};