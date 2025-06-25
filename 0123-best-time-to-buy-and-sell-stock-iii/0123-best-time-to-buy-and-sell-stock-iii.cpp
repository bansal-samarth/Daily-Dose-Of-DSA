class Solution {
public:
    int dp[100001][2][3];
    int solve(vector<int>& prices, int idx, int buy, int k) {
        if(idx == prices.size() || k == 0)
            return 0;
        
        if(dp[idx][buy][k] != -1)
            return dp[idx][buy][k];
        
        int skip = solve(prices, idx + 1, buy, k);

        int prof = 0;
        if(buy)
            prof = solve(prices, idx + 1, !buy, k) - prices[idx];
        else
            prof = solve(prices, idx + 1, !buy, k - 1) + prices[idx];
        
        return dp[idx][buy][k] = max(skip, prof);
    }

    int maxProfit(vector<int>& prices) {
        
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, true, 2);
    }
};