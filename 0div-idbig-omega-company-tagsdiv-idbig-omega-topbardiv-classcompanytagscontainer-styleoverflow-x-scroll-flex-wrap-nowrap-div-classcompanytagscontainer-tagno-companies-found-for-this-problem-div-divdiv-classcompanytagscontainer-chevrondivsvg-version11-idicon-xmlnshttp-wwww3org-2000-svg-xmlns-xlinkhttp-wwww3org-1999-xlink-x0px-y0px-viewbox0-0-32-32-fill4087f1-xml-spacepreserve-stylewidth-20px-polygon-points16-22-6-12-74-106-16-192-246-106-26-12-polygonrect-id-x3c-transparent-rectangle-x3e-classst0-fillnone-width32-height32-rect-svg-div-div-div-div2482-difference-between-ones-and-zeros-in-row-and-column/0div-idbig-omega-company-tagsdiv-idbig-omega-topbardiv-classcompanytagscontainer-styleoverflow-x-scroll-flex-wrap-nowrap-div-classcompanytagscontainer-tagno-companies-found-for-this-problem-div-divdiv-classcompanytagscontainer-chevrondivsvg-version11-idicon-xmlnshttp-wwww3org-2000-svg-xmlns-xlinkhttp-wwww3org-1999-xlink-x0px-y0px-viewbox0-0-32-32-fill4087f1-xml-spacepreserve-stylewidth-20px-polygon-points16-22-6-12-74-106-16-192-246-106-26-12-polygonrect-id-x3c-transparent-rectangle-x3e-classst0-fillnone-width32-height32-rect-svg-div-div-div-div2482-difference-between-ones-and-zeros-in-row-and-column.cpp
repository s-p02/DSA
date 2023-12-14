class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<int> onesRow(n,0);
        vector<int> zeroRow(n,0);
        vector<int> onesCol(m,0);
        vector<int> zeroCol(m,0);
        
        for(int i=0;i<n;i++){
            int res=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    res++;
                }
            }
            onesRow[i]=res;
            zeroRow[i]=m-res;
        }
        
        for(int i=0;i<m;i++){
            int res=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==1){
                    res++;
                }
            }
            onesCol[i]=res;
            zeroCol[i]=n-res;
        }
        
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]= onesRow[i] -zeroRow[i] +onesCol[j] -zeroCol[j];
            }
        }
        
        return ans;
        
        
    }
};