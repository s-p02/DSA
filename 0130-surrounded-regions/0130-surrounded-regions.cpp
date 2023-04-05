class Solution {
public:
    void dfs(int row, int col ,vector<vector<char>>& board,vector<vector<int>>& vis, int delrow[], int delcol[]){
        vis[row][col]=1;
        int n= board.size();
        int m= board[0].size();
        for(int i=0;i<4;i++){
            int nrow= row+delrow[i];
            int ncol= col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                dfs(nrow, ncol,board,vis,delrow,delcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[]={1,0,-1,0};
        int delcol[]={0,1,0,-1};
        
        
        // first row
        for(int i=0;i<m;i++){
            if(vis[0][i]==0 && board[0][i]=='O'){
                dfs(0,i,board,vis,delrow,delcol);
            }
        }
        
        // last row
        for(int i=0;i<m;i++){
            if(vis[n-1][i]==0&& board[n-1][i]=='O'){
                dfs(n-1,i,board,vis,delrow,delcol);
            }
        }
        
        // first col
        
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && board[i][0]=='O'){
                dfs(i,0,board,vis,delrow,delcol);
            }
        }
        
        // last col
        
        for(int i=0;i<n;i++){
            if(vis[i][m-1]==0 && board[i][m-1]=='O'){
                dfs(i,m-1,board,vis,delrow,delcol);
            }
        }
        
        // now replace 'o' whose is not visited 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }

    }
};