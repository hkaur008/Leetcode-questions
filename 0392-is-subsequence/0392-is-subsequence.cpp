class Solution
{
    public:
        int dp[100][10000];
    bool helper(int p, int n, string s, string t)
    {
        if (p == s.size())
            return 1;

        for (int i = n; i < t.size(); i++)
        {
            if (s[p] == t[i])
                if (helper(p + 1, i + 1, s, t) == 1)
                    return 1;
        }

        return 0;
    }
    bool isSubsequence(string s, string t)
    {

       	// return helper(0, 0, s, t);

        int n = s.length(), m = t.length();
        int j = 0;
       	// For index of s (or subsequence

       	// Traverse s and t, and
       	// compare current character
       	// of s with first unmatched char
       	// of t, if matched
       	// then move ahead in s
        for (int i = 0; i < m and j < n; i++)
            if (s[j] == t[i])
                j++;

       	// If all characters of s were found in t
        return (j == n);
    }
};