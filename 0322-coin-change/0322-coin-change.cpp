class Solution {
public:
    int solve(int n, int i, vector<int> &coins, int amount, vector<vector<int>> &dp) {
        if(amount == 0) return 0;

        if(i == n) return 1e9;

        if(dp[i][amount] != -1) return dp[i][amount];
        
        int p = 1e9;

        if(coins[i] <= amount) {
            p = solve(n, i, coins, amount - coins[i], dp) + 1;
        }
        int np = solve(n, i+1, coins, amount, dp);

        return dp[i][amount] = min(p, np);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount +1, -1));

        int ans = solve(n, 0, coins, amount, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};