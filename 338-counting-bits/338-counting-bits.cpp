class Solution {
public:
    
    int countB( int n , vector < int > & ans )
    {
        
      if( ans[n]!=-1)
          return ans[n];
        
        else 
            
        {
            if((n&1)==1)
                return ans[n]=1+countB(n>>1 , ans);
            else
                return ans[n]= countB(n>>1,ans);
            
        }
        
    }
    vector<int> countBits(int n) {
        
        vector <int> ans (n+1, -1);
      
        ans[0]= 0;
        
        if(n>0)
        {ans[1]=1;
        countB(n, ans);
        
        for( int i = n ; i>= 0 ; i--)
        { if(ans[i]==-1)
            ans[i]=countB(i, ans);
        }
        }
        return ans;
        
    }
};