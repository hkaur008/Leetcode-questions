class Solution {
public:
    
   static bool compare ( string a , string b )
    {
        
        string t1 = a + b ;
        string t2 = b + a;
        
        if( t1.compare(t2)>0)
            return 1;
            
         else 
              return 0;
    }
    
    string largestNumber(vector<int>& nums) {
        
        vector <string> ans ;
        
        for(auto i : nums)
            ans.push_back(to_string(i));
        
        sort(ans.begin(), ans.end(), compare);
        
        // string str(ans.begin(), ans.end());
        
        string str = "";
        
        for( auto i : ans)
            str=str+i;
        
                if(str[0]=='0') return "0";

        return str;
    }
};