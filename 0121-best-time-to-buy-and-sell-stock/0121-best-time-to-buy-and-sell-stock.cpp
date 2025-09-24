class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;

        int mini = INT_MAX;

        for(int i = 0; i < prices.size(); i++) {
            mini = min(mini, prices[i]);
            prof = max(prof, prices[i] - mini);
        }

        return prof;
    }
};