class Solution {
public:
    inline int ctoi(char c)
{
    return c - '0';
}
    
    int decode(string s , int n , vector <int> &sum )
    {
        if (n == 0)
            return 1 ;
        if(n <1)
            return 0;
             
        if(sum[n]!=-1)
            return sum[n];
        

        int a = ctoi(s[n-1]);
        
        
        if( a>=1 && a<=26)
        {   if(sum[n]==-1) sum[n]=0;
            sum[n]+= decode(s,n-1, sum);
        }
        
        if(n>=2)
        {
        int b =  ctoi(s[n-2]); 
        if(b!=0 && b*10+a>=1 && b*10+a<=26)
            {   if(sum[n]==-1) sum[n]=0;
                sum[n]+=decode(s,n-2, sum);
            }
         }
        
        if(sum[n]==-1) return sum[n]=0;
        return sum[n];
        
        
    }
        
    
    int numDecodings(string s) {
        
        int n = s.size();
        vector <int> sum(n+1,-1);
        return sum[n]= decode(s, n, sum);
    }
};