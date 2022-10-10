class Solution {
public:
    vector<int> getRow(int n) {
        
        vector < int> ans(n+1, 0) ;
        ans[0]=1;
        
        
        for( int i = 1 ; i<=n; i++)
        {
           ans[i]=  ((long long)ans[i-1] * (n-i+1))/i;
        }
        
        return ans;
    }
};