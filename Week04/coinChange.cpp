class Solution {
public:

    int coinChange (vector<int>& coins, int amount) {
        vector<int> memory(amount,0);
        return findWay(coins,amount,memory);
    }

    int findWay (const vector<int>& coins, int amount,vector<int>& memory) {
        if (amount < 0) {
            return -1;
        }
        if (amount == 0) {
            return 0;
        }
        if (memory[amount - 1] != 0) {
            return memory[amount -1];
        }
        int min = INT_MAX;
        for (int i = 0;i<coins.size();i++) {
            int res = findWay(coins,amount-coins[i],memory);
            if (res >= 0 && res < min) {
                min = res + 1;
            }
        }
        memory[amount - 1]  = (min == INT_MAX ? -1 : min);
        return memory[amount - 1];
    }
}; 