//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[]= {-1,0,1,0};
        int delcol[]= { 0,1,0,-1};
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    vector<pair<int,int>> vc;
                    dfs(i,j,grid,vis, delrow, delcol,i,j,vc);
                    st.insert(vc);
                }
            }
        }
        return st.size();
    }
    
    void dfs(int row, int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int delrow[],
    int delcol[], int baserow, int basecol,vector<pair<int,int>> &vc){
        vis[row][col]=1;
        vc.push_back({row-baserow,col-basecol});
        int n= grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow= row+delrow[i];
            int ncol= col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && 
            grid[nrow][ncol]==1){
                dfs(nrow, ncol, grid, vis,delrow,delcol, baserow,basecol,vc);
            }
        }
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends