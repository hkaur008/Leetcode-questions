class Solution
{
    public:
    bool containAllStars(int j, string &p) {
	for(int k = j; k < p.size(); k++)
		if(p[k] != '*') return false;
	return true;
}

bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
	if(i == s.size()) return j == p.size() || containAllStars(j, p);
	if(j == p.size()) return i == s.size();
	if(dp[i][j] != -1) return dp[i][j];
	if(s[i] == p[j] || p[j] == '?') return dp[i][j] = solve(i + 1, j + 1, s, p, dp);
	if(p[j] == '*') return dp[i][j] = solve(i, j + 1, s, p, dp) || solve(i + 1, j, s, p, dp);
	return dp[i][j] = false;
}

bool isMatch(string s, string p) {
	vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
	return solve(0, 0, s, p, dp);
}
};