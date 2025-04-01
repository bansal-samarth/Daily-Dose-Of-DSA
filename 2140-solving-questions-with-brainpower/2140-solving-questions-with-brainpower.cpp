class Solution {
public:
    vector<long long> dp;
    long long solve(vector<vector<int>>& ques, int idx) {
        if(idx >= ques.size())
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        long long skip = solve(ques, idx + 1);

        long long take = solve(ques, idx + ques[idx][1] + 1) + ques[idx][0];

        return dp[idx] = max(skip, take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.assign(n, -1);
        return solve(questions, 0);
    }
};