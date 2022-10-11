class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        int l=0  , h =  n-1;
        
        int mid;
        
        while(l<h)
        {
            mid = l + (h-l)/2;
            if(arr[mid]<arr[mid+1])
                l = mid+1 ;
            else    
            {h = mid;}
            
        }
        
        return l;
    }
};