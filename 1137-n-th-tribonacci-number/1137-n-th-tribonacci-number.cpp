class Solution
{
    public:
        int dp[38];

    int helper(int n)
    {
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = helper(n - 1) + helper(n - 2) + helper(n - 3);
    }
    int tribonacci(int n)
    {

        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        return helper(n);
    }
};