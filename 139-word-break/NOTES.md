```
class Solution {
public:
int dp [301] ;
int helper(int i , string s, int n , set <string>& st)
{
if( i == n) return 1;
if(dp[i]!=-1) return dp[i];
string str ;
for( int j = i ; j< n ; j++)
{
str+=s[j];
if( st.find(str)!=st.end())
{
if(helper(j+1,s,n,st)) return dp[i]=1;
}
}
return dp[i]=0;
}
bool wordBreak(string s, vector<string>& wordDict) {
int n = s.size();
memset(dp ,-1, sizeof(dp));
set <string> st ;
for(auto a : wordDict)
{
st.insert(a);
}
return helper(0, s, n , st);
}
};
```
​
How is repetion ?
​