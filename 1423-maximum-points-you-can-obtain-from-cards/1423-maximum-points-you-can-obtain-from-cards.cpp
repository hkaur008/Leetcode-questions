class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int lo=0 , hi= 0 ;
        int sum=0 ; int n = card.size();
        int K=n-k;
        int total_sum = 0 ;
        for(int i = 0 ; i< n ; i++)
        {
            total_sum += card[i];
        }
        while(K--)
        {
           sum = sum + card[hi];
            hi++;
        }
        int ans = sum;
        
        // cout<< hi<<" "<<sum<<endl;
        while(hi<n)
        {
            sum = sum - card[lo] +card[hi];

            ans = min(ans , sum);
            hi++;
            lo++;
            // cout<< hi<<" "<<sum<<endl;

        }
        
        return total_sum-ans ;
    }
};