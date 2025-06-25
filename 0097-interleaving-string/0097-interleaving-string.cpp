class Solution {
public:
    int dp[101][101];
    bool solve(string& s1, string& s2, string& s3, int i, int j, int n1, int n2, int n3) {
        if(i + j == n3)
            return true;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        bool take1 = false;
        if(i != n1 && s1[i] == s3[i + j])
            take1 = solve(s1, s2, s3, i+1, j, n1, n2, n3);
        
        bool take2 = false;
        if(j != n2 && s2[j] == s3[i + j])
            take2 = solve(s1, s2, s3, i, j+1, n1, n2, n3);
        
        return dp[i][j] = take1 || take2;            
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        if(n1 + n2 != n3)
            return false;

        memset(dp, -1, sizeof(dp));
        
        return solve(s1, s2, s3, 0, 0, n1, n2, n3);
    }
};