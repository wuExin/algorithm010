class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,0);
        dp[0] = 1;
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        for ( int i = 1; i < n; i++) {
            dp[i] = min(dp[p2] * 2,min(dp[p3] * 3,dp[p5] * 5));
            if (dp[i] == dp[p2] * 2) {
               p2++; 
            }
            if (dp[i] == dp[p3] * 3) {
               p3++; 
            }
            if (dp[i] == dp[p5] * 5) {
               p5++; 
            }
        }
        return dp[n - 1];
    }
};