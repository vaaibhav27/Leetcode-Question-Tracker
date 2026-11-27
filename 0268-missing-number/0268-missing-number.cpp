class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n+1, -1);
        int a = 0;
        for(int i = 0; i < n; i++) {
            ans[nums[i]] = 1;
        }
        for(int i = 0; i <= n; i++) {
            if(ans[i] == -1) a = i;
        }
        return a;
    }
};