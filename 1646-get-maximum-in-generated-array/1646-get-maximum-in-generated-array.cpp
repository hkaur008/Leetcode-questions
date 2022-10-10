class Solution
{
    public:
        int dp[101];
    int helper(int n)
    {
        if (dp[n] != -1) return dp[n];
        if (n % 2 == 0)
        {
            return dp[n] = helper(n / 2);
        }
        else
        {
            return dp[n] = helper((n - 1) / 2) + helper(((n - 1) / 2) + 1);
        }
    }
    int getMaximumGenerated(int n)
    {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        int ans = 0 ;
        
        for( int i = 0 ; i<= n ; i++)
        {
            
         ans = max(ans , helper(i));   
        
        }
        return ans;
    }
};