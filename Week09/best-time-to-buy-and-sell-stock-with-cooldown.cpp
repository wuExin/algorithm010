class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if (length == 0) return 0;
        vector<vector<int>> dp(length,vector<int>(3));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for (int i = 1; i < length;i++) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][2] - prices[i]);
            dp[i][2] = dp[i-1][0];
        }
        return max(dp[length-1][0],dp[length-1][2]);
    }
};