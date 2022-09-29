class Solution
{
    public:

        int brute_force(vector<int> &nums)
        {
            int n = nums.size();
            int max_product = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                int currProduct = 1;
                for (int j = i; j < n; j++)
                {
                    currProduct *= nums[j];
                    if (currProduct > max_product)
                        max_product = currProduct;
                }
            }

            return max_product;
        }

    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int ma = nums[0], mi = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < 0)
                swap(ma, mi);

            ma = max(nums[i], ma *nums[i]);
            mi = min(nums[i], mi *nums[i]);

            if (ma > ans) ans = ma;
        }
        return ans;
    }
};