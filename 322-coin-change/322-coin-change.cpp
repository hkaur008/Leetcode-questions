class Solution
{
    public:

       	// solve(x) returns minimum ways to form a particular number x 
       	// 20000 used by constrains as it was not accepting int_max giving overflow
        int solve(vector<int> &coins, int amount)
        {
            if (amount == 0)
                return 0;
            if (amount < 0)
                return 20000;

            int minimum_coins = 20000;
            for (int i = 0; i < coins.size(); i++)
            {
                minimum_coins = min(minimum_coins, solve(coins, amount - coins[i]) + 1);
            }

            return minimum_coins;
        }

    int minimum_coins[20000];
    int solve_dp_memo(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return minimum_coins[amount] = 0;
        if (amount < 0)
            return 20000;

        if (minimum_coins[amount] != -1)
            return minimum_coins[amount];

        int best = 20000;
        for (int i = 0; i < coins.size(); i++)
        {
            best = min(best, solve(coins, amount - coins[i]) + 1);
        }

        return minimum_coins[amount] = best;
    }

    int solve_dp_tab(vector<int> &coins, int amount)
    {
        minimum_coins[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (auto c: coins)
            {

                if (i - c >= 0 && minimum_coins[i] > 1 + minimum_coins[i - c] )
                {
                    minimum_coins[i] = 1 + minimum_coins[i - c];
                }
            }
        }

        return minimum_coins[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {

        sort(coins.begin(), coins.end());
        int num = coins.size();

        memset(minimum_coins, 20000, sizeof(minimum_coins));

        unsigned int res = solve_dp_tab(coins, amount);

        if (res >= 20000)
            res = -1;
        return res;
    }
};