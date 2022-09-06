class Solution {
public:
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector <int> adj [n];
        
        for( int i=0 ; i< edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);

        
        }
        
//         vector <int> visited (n, false);
        
//         queue<int> q;

//         for( int i = 0 ; i<n ;i++)
//         {
//             if(!visited[i])
//             {
//                 q.push(i);
                
//                 while(!q.empty())
//                 {
//                     int u= q.front();
//                         q.pop();
                    
//                     for(int v: adj[u])
//                     {
//                         visited[v]=true;
//                         q.push(v);
//                     }
//                 }
//             }
//         }
        
        vector <int> result;
        for( int i =0 ; i< n ; i++)
            if(adj[i].size()==0)
            {
                result.push_back(i);
            }
    return result;
    }
};