class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        
       int n = arr.size(); 
            
        unordered_map<int,int> prevSum;
                
        int currSum = 0;
         prevSum[0]=-1;
        
        if(n<2)
            return false;
        
        
        for( int i = 0 ; i< n ; i++)
        {
            currSum += arr[i];
        
        if(k!=0)
                currSum=currSum%k;
            
          if(prevSum.find(currSum)!=prevSum.end())
          { if(i-prevSum[currSum]>1)
                  return true;
          }
           else { prevSum[currSum]=i;}
        }
        
     
        return false;
    }
};