class Solution
{
    public:
        int dp[1002];
    int helper(int i, vector<int> &cost)
    {
        if (i >= cost.size())
            return 0;
        if (dp[i] != -1) 
            return dp[i];
        return dp[i] = min(cost[i] + helper(i + 2, cost), cost[i] + helper(i + 1, cost));
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        memset(dp, -1, sizeof(dp));
        return min(helper(0, cost), helper(1, cost));
    }
};