//Memoization
class Solution {
    int minpath(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>& dp,int m){
        if(j<0 || j>=m) return 1e9;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = matrix[i][j]+ minpath(i-1,j,matrix,dp,m);
        int ld = matrix[i][j]+ minpath(i-1,j-1,matrix,dp,m);
        int rd = matrix[i][j]+ minpath(i-1,j+1,matrix,dp,m);
        
        return dp[i][j]= min(up,min(ld,rd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            mini= min(mini,minpath(n-1,j,matrix,dp,n));
        }
        return mini;
    }
};