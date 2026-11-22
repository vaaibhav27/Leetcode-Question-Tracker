class Solution {
public:
    bool solve(int i, int s, int n, vector<int> &nums, vector<vector<int>> &dp, int t) {
        if(s == t) return true;
        if(s > t) return false;
        if(i == n) return false;
        
        if(dp[i][s] != -1) return dp[i][s];

        int p = solve(i+1, s + nums[i], n, nums, dp, t);
        int np = solve(i+1, s, n, nums, dp, t);

        return dp[i][s] = p || np;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int t = 0;
        int sum = 0;
        for(int i : nums) {
            sum += i;
        }
        t = sum / 2;
        vector<vector<int>> dp(n, vector<int> (t + 1, -1));
        if(sum % 2 == 0) {
            return solve(0, 0, n-1, nums, dp, t);
        }
        return false;
    }
};