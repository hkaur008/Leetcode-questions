class Solution {
public:
    
     int largestRectangleArea(vector<int> &heights)
        {

            stack<int> st;

            int n = heights.size();

            vector<int> left(n);
            vector<int> right(n);
            for (int i = 0; i < n; i++)
            {
                while (!st.empty() && heights[st.top()] >= heights[i])
                {

                    st.pop();
                }

                if (st.empty())
                {
                    left[i] = 0;
                }
                else
                {
                    left[i] = st.top() + 1;
                }

                st.push(i);
            }
            
            while(!st.empty())
                st.pop();
            
             for (int i = n-1; i>= 0; i--)
            {
                while (!st.empty() && heights[st.top()] >= heights[i])
                {

                    st.pop();
                }

                if (st.empty())
                {
                    right[i] = n-1;
                }
                else
                {
                    right[i] = st.top()-1;
                }

                st.push(i);
            }
            int ans = 0;
            for( int i = 0 ; i<n ; i++)
                ans = max( ans , heights[i]*(right[i]-left[i]+1));
    
            return ans;
        }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
      
        
        vector<vector<int>> mat (m, vector < int> (n, 0))  ;
        for(int j = 0; j<n ; j++ )
            {
               mat[0][j]= matrix[0][j]-'0';
            }
        
        
        for( int i =1 ; i<m; i++)
        {
            for(int j = 0; j<n ; j++ )
            {
                if(matrix[i][j]=='1')
                {
                    mat[i][j]= 1+mat[i-1][j];
                
                }
            }
        }
        
        int ans = 0;
        for( int i = 0 ; i< m ; i++)
            
        {
         ans = max( ans , largestRectangleArea(mat[i]) );   
        }
        
        return ans ;
    }
};