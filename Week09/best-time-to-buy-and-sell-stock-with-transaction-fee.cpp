class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int length = prices.size();
        if (length == 0) return 0;
        vector<vector<int>> dp(length,vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1;i < length;i++) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]);
        }
        return dp[length-1][0];
    }
};