class Solution {
public:
    void bfs(int i, int j,vector<vector<char>>& grid,vector<vector<int>>&vis ){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            
            //Traverse neighbours
            if(col-1>=0 && grid[row][col-1]=='1'&& !vis[row][col-1]){
                vis[row][col-1]=1;
                q.push({row,col-1});
            }
            if(col+1<m && grid[row][col+1]=='1'&& !vis[row][col+1]){
                vis[row][col+1]=1;
                q.push({row,col+1});
            }
            if(row-1>=0 && grid[row-1][col]=='1'&& !vis[row-1][col]){
                vis[row-1][col]=1;
                q.push({row-1,col});
            }
            if(row+1<n && grid[row+1][col]=='1'&& !vis[row+1][col]){
                vis[row+1][col]=1;
                q.push({row+1,col});
            }   
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};