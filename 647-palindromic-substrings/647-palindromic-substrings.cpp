class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        int l , r;
        int count=0;

        // find all the palindrome starting from i as mid instead of start
        for( int i = 0 ; i<n; i++)
        {
            l = i;
            r=i;
           
           // odd length palindrome 
            while(l>=0 && r<n && s[l]==s[r] )
            {
                count++;
                l--;
                r++;
            }

            //even length palindrome 

            if(i+1<n)
            {
                l=i;
                r=i+1;
            
            
            while(l>=0 && r<n && s[l]==s[r] )
            {
                count++;
                l--;
                r++;
            }

            }
        }

        return count;
    }
};