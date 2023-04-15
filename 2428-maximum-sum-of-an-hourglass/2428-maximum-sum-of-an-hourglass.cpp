class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& grid){
        int n= grid.size();
        int m= grid[0].size();
        if(i>=0 && i<n && j>=0 && j<m){
            return true;
        }
        return false;
    }
    int maxSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(i-1,j-1,grid)&&
                check(i-1,j,grid) &&
                check(i-1,j+1,grid)&&
                check(i+1,j-1,grid)&&
                check(i+1,j,grid)&&
                check(i+1,j+1,grid)){
                    int sum= grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1]+grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1]+grid[i][j];
                    maxi=max(maxi,sum);
                }
                    
            }
        }
        return maxi;
    }
};