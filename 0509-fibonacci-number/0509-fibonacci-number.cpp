class Solution {
public:
    int dp[31];
    
    int helper ( int n)
    {
        if( dp[n] !=-1)
            return dp[n];
        return dp[n] = helper(n-1) + helper(n-2);
    }
    int fib(int n) {
        
        memset(dp, -1 ,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        
       return helper(n);
    }
};