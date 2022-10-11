class Solution
{
    public:
       
    int dp[500][500];
        int helper(int p1, int p2, string word1, string word2)
        {
            
            if(p1==word1.size()) // we need to insert rest element in word2
                return word2.size()-(p2);
            if(p2==word2.size()) //we need to delete left element in word1
                return word1.size()-(p1); 
            
            if(dp[p1][p2]!=-1)
                return dp[p1][p2];
                
            if (word1[p1] == word2[p2])
            {
                return dp[p1][p2]=helper(p1 + 1, p2 + 1, word1, word2);
            }
            else
            {
                return dp[p1][p2]=min(1 + helper(p1 + 1, p2, word1, word2),	//delete

                    min(1 + helper(p1 + 1, p2 + 1, word1, word2),	//replace
                        1 + helper(p1, p2 + 1, word1, word2)));	//insert
            }
        }

    int minDistance(string word1, string word2)
    {
       memset(dp, -1, sizeof(dp));
        return helper(0, 0, word1, word2);
    }
};