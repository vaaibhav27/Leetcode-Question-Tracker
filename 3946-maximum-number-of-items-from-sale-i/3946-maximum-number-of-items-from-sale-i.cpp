
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> bonus(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    bonus[i]++;
                }
            }
        }

        const int NEG = -1e9;

        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int price = items[i][1];

            vector<int> take(budget + 1, NEG);

            for (int b = price; b <= budget; b++) {

                if (dp[b - price] != NEG) {
                    take[b] = dp[b - price] + 1 + bonus[i];
                }

                if (take[b - price] != NEG) {
                    take[b] = max(take[b], take[b - price] + 1);
                }
            }

            for (int b = 0; b <= budget; b++) {
                dp[b] = max(dp[b], take[b]);
            }
        }

        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b]);
        }

        return ans;
    }
};
