class Solution {
public:
	long long countJumps(int n) {
		long long *dp = new long long[n + 1];
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; i ++) {
			for (int j = 1; j <= i; j ++){
				dp[i] += dp[i-j];
			}
		}
		return dp[n];
    }
};