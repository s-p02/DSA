class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n= grid.size();
        int m= grid[0].size();
        int vis[n][m];
        int cntFresh=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j]=0;
                }
                // count fresh oranges in beginning
                if (grid[i][j] == 1) cntFresh++;
            }
        }
        int tm=0;
        //4 directions
        int delrow[]={-1,0,1,0};
        int delcol[] = {0, 1, 0, -1}; 
        int cnt=0;
        while(!q.empty()){
            int row= q.front().first.first;
            int col=q.front().first.second;
            int time= q.front().second;
            q.pop();
            tm= max(tm,time);
            for(int i=0;i<4;i++){
                int nrow= row+delrow[i];
                int ncol= col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }
        
        // check if any fresh orange is still pending
        if(cnt!=cntFresh) return -1;
        else{
            return tm;
        }
        
        
    }
};