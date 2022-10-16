// Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            dp[0][j]= matrix[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up= matrix[i][j] + dp[i-1][j];
                
                int ld= matrix[i][j];
                if(j-1>=0) ld= ld+ dp[i-1][j-1];
                else ld= ld+1e9;
                
                int lr= matrix[i][j];
                if(j+1<n) lr= lr+ dp[i-1][j+1];
                else lr= lr+1e9;
                
                dp[i][j]= min(up,min(ld,lr));            
            }
        }
        
        // final ans is the minimum of last row
        int mini= INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(mini,dp[n-1][j]);
        }
        
        return mini;
    }
};


//Memoization
// class Solution {
//     int minpath(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>& dp,int m){
//         if(j<0 || j>=m) return 1e9;
//         if(i==0) return matrix[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int up = matrix[i][j]+ minpath(i-1,j,matrix,dp,m);
//         int ld = matrix[i][j]+ minpath(i-1,j-1,matrix,dp,m);
//         int rd = matrix[i][j]+ minpath(i-1,j+1,matrix,dp,m);
        
//         return dp[i][j]= min(up,min(ld,rd));
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int mini=INT_MAX;
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         for(int j=0;j<n;j++){
//             mini= min(mini,minpath(n-1,j,matrix,dp,n));
//         }
//         return mini;
//     }
// };