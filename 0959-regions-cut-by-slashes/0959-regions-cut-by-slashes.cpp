class Solution {
public:
    
     void dfs(vector<vector<int>> &mat, int i, int j,int n, vector<vector<int>> &vis){
         
        if(i>=0 && j>=0 && i<n && j<n && vis[i][j]==0 && mat[i][j]==1){
            
            vis[i][j] = 1;
            dfs(mat, i+1, j, n,vis);
            dfs(mat, i-1, j, n,vis);
            dfs(mat, i, j+1, n,vis);
            dfs(mat, i, j-1, n,vis);
        }
    }
    
    // it is basically we are dividing the current matrix cell in grid of 9 cell earlier mat is completely filed then slashes are 0 means boundaries we are removing boundaries and hence forth all the disconnected comments will be counted and returned
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(n*3 , vector<int>(n*3, 1));
        for( int i = 0 ; i < n; i++)
        {
            for( int j = 0 ; j <n ; j++)
            {
                if(grid[i][j]=='/') // (0,2) , (1, 1) , (2, 0) 
                {
                mat[i*3][j*3 + 2] = mat[i*3 + 1][j*3 + 1] = mat[i*3 + 2][j*3] = 0;
 
                }    
                else if(grid[i][j]=='\\')  // (0,0) , (1,1) , (2,2) 
                {
               mat[i*3][j*3] = mat[i*3 + 1][j*3 + 1] = mat[i*3 + 2][j*3 + 2] = 0;
                }
            }
        }
        
      vector<vector<int>> vis(n*3 , vector<int>(n*3, 0));

        int count  = 0, N = n*3;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(mat[i][j]==1 && vis[i][j]==0){
                    count++;
                    dfs(mat, i, j ,N, vis);
                }
            }
        }
        return count;
    }
};