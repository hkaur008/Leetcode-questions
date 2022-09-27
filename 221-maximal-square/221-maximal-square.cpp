class Solution
{
    public:
        int maximalSquare(vector<vector < char>> &matrix)
        {

            int m = matrix.size();
            int n = matrix[0].size();

            int dp[301][301] = { 0 };
            int maxi = 0;
            for (int i = 0; i < m; i++)
            {
                dp[i][0] = matrix[i][0] - '0';
                if (maxi < dp[i][0]) maxi = dp[i][0];
            }

            for (int j = 0; j < n; j++)
            {
                dp[0][j] = matrix[0][j] - '0';
                if (maxi < dp[0][j]) maxi = dp[0][j];
            }

            for (int i = 1; i < m; i++)
                for (int j = 1; j < n; j++)
                {
                    if (matrix[i][j] - '0' == 1)
                    {
                        dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j-1]));
                        maxi = max(dp[i][j], maxi);
                    }
                }

            return maxi*maxi;
        }
};