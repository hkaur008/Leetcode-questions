class Solution {
public:
    
    void dfs(vector < int> & visited, vector<vector<int>>& rooms, int i)
    {
        visited[i]= true;
         for( int u : rooms[i])
          {  if(!visited[u])
                dfs(visited, rooms, u);}
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int v = rooms.size();
        
        vector <int> visited (v,false);
        // visited[0]=true;
                dfs(visited, rooms, 0);
        
        
        for( int x : visited)
        {
            if(x==false)
                return false;
        }
        
        return true;
    }
};