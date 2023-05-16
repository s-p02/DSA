class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        if(grid[0][0]==1){
            return -1;
        }
        if(grid[0][0]==0 && grid.size()==1){
            return 1;
        }
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int dis= it.first;
            int row= it.second.first;
            int col= it.second.second;
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    int nrow= row+dr;
                    int ncol= col+dc;
                    if(nrow>=0&& nrow<n && ncol>=0 && ncol<m 
                      && grid[nrow][ncol]==0 
                      && dis+1<dist[nrow][ncol]){
                        if(nrow==n-1 && ncol ==m-1){
                            return dis+1;
                        }
                        dist[nrow][ncol]= dis+1;
                        q.push({dis+1,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};