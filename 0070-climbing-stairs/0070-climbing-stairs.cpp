class Solution {
public:
    int memo(int n) {
        if(n == 0)
            return 1;
        
        int one = memo(n - 1);

        int two = 0;
        if(n > 1)
            two = memo(n - 2);
        
        return one + two;
    }
    int climbStairs(int n) {
        // return memo(n);

        // tab
        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for(int i = n-1; i >= 0; i--) {
            int one = dp[i + 1];

            int two = 0;
            if(i != n-1)
                two = dp[i + 2];
            
            dp[i] = one + two;
        }

        return dp[0];
    }
};