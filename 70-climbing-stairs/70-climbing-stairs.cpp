class Solution {
public:
    
   int climbs( int n , vector <int> &climb)
   {
       if(n==0)
           return 1;
        if(n<0)
            return 0;
        if(climb[n]!=-1)
            return climb[n];
       else 
       return climb[n]=climbs(n-1,climb)+climbs(n-2,climb);
       
        
   }

    int climbStairs(int n) {
       
          vector <int> climb(n+1,-1);
       
        
        return climbs(n,climb);
        
    }
};