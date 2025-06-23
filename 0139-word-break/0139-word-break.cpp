class Solution {
public:
    int dp[1001];
    bool solve(string& s, unordered_set<string>& dict, int idx) {
        if(idx == s.size())
            return true;

        if(dp[idx] != -1)
            return dp[idx];

        for(string word : dict) {
            int len = word.size();
            string str = s.substr(idx, len);

            if(word == str) {
                if(solve(s, dict, idx + len))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        memset(dp, -1, sizeof(dp));
        return solve(s, dict, 0);
    }
};