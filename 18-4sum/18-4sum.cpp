class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; ){
            long sum = nums[i];
            for(int j = i + 1; j < n; ){
                sum += nums[j];
                int c = j + 1, d = n - 1;
                while(c < d){
                    long req = nums[c] + nums[d];
                    if(sum + req < target){
                        c++;
                    }
                    else if(sum + req > target){
                        d--;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[c], nums[d]});
                        int prev = nums[c];
                        c++;
                        while(c < d and nums[c]== prev){
                            c++;
                        }
                    }
                }
                sum -= nums[j];
                int prev = nums[j];
                j++;
                while(j < n and nums[j] == prev)
                    j++;
            }
            int prev = nums[i];
            i++;
            while(i < n and nums[i] == prev)
                i++;
        }
        return ans;
    }
};