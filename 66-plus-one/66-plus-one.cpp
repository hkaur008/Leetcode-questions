class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int crr = 1; int rem ;
        for ( int i = n-1 ; i >=0 ;i-- )
        { 
            if(crr==0)
                break;
            rem=(digits[i]+crr)%10; 
            cout<<rem<<endl;
           crr = (digits[i]+crr)/10;
            digits[i]=rem;
        }
        
        if(crr)
            digits.insert(digits.begin(), crr);
        
        return digits;
    }
};