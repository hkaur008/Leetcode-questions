class Solution {
public:
    
     void dfs(vector<vector<int>> &adj, int source, vector<int> &vis){
         
         vis[source]=1;
         for(auto x : adj[source])
         {
             if(!vis[x])
                 dfs(adj , x , vis);
         }
      
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        
        vector<vector<int>> adj(N);

        vector<int> vis(N , 0);
        
        for(int i = 0 ; i < N ; i++)
        {
            for( int j = 0 ; j < N ; j++)
            {
              if(isConnected[i][j])
                  adj[i].push_back(j);
            }
        }

        int count  = 0;
        for(int i = 0; i<N; i++){
                if( vis[i]==0){
                    count++;
                    dfs(adj, i, vis);
                }
        }
        return count;
        
    }
};


// 1 1 0
// 1 1 0    
// 0 0 1
    
    // 1 0 0 
    // 0 1 0
    // 0 0 1

   // 1 0 0 1 
   // 0 1 1 0
   // 0 1 1 1
   // 1 0 1 1    