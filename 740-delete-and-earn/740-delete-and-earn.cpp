class Solution
{
    public:

        int deleteAndEarn(vector<int> &nums)
        {
            int frq[20005] = { 0 };
            int dp[20005] = { 0 };
            int maxi = 0;
            for (auto x: nums)
            { if (x > maxi)
                    maxi = x;

                    frq[x]++;}
                
 cout<<maxi<<endl;
            dp[0] = 0;
            dp[1] = frq[1];
            
            for (int i = 2; i <= maxi; i++)
                
            {dp[i] = max(dp[i - 1], (dp[i - 2] + i *frq[i]));
            cout<<i<<" "<<dp[i]<<endl;
            }

            return dp[maxi];
        }
};