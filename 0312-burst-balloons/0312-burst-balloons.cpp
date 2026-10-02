class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> A(n + 2, 1);
        for (int i = 0; i < n; i++) {
            A[i + 1] = nums[i];
        }
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1;
                
                int left = i - 1;
                int right = j + 1;
                
                for (int k = i; k <= j; k++) {
                    int coins = A[left] * A[k] * A[right];
                    int total = dp[left][k] + dp[k][right] + coins;
                    dp[left][right] = max(dp[left][right], total);
                }
            }
        }
        
        return dp[0][n + 1];
    }
};
