class Solution
{
    public:
        int trap(vector<int> &heights)
        {

            int n = heights.size();

            vector<int> max_left(n), max_right(n);
            if (n > 2)
            {
                max_left[0] = 0;
                int ml = heights[0];

                max_right[n - 1] = 0;
                int mr = heights[n-1];
                
                for (int i = 1; i < n; i++)
                {
                    max_left[i] = ml;

                    if (ml < heights[i])
                        ml = heights[i];
                }

                for (int i = n - 2; i >= 0; i--)
                {
                    max_right[i] = mr;

                    if (mr < heights[i])
                        mr = heights[i];
                }
                int ans = 0;
                for (int i = 1; i < n-1; i++)
                    if( heights[i]<max_left[i] and heights[i]<max_right[i])
                    ans = ans + min(max_left[i], max_right[i]) - heights[i];

                return ans;
            }

            return 0;
        }
};