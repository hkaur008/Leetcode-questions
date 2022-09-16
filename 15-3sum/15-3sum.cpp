class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> triples ; 
            
        for( int i = 0 ; i< n-2 ; i++ )
        {
            
            if( i >0 && arr[i]==arr[i-1])
                continue;
            
            int lo = i+1;
            int  hi = n-1;
            
            while(lo <hi)
            {
                if(arr[i]+arr[lo]+arr[hi]==0)
                {triples.push_back({arr[i], arr[lo],arr[hi]});
                 
                 while( lo<hi and arr[lo] == arr[lo+1])
                      lo++;
                 
                 while( lo < hi and arr[hi] == arr[hi-1])
                     hi--;
                 
                 lo++;
                 hi--;
                
                }
                else if (arr[i]+arr[lo]+arr[hi]<0)
                {lo++;}
                else 
                {  hi--; }
                    
            }
        }
        
        
        return triples;
        
    }
};