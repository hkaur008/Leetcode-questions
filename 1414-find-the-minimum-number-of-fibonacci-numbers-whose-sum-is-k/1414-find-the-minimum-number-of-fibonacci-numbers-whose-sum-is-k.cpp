class Solution {
public:
    int findMinFibonacciNumbers(int A) {
        
          vector<int>v;
    int a=0,b=1,c=a+b;


    while(c<=A)
    {
        v.push_back(c);
        
        a=b;
        b=c;
        c=a+b;
    }
       int res=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(v[i] > A)
                continue;
            res+=A/v[i];
            A=A%v[i];
            if(A == 0)
                break;
        }
        return res;
    }
};