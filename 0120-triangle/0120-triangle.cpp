// space optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<int> nex(n,0);
        //base case:
        for(int j=0;j<n;j++){
            nex[j]= triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=0;j<=i;j++){
                int down= triangle[i][j]+nex[j];
                int diag= triangle[i][j]+nex[j+1];
                curr[j]=min(down,diag);
            }
            nex=curr;
        }
        return nex[0];
    }
};

// // Tabulation
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n= triangle.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         //base case:
//         for(int j=0;j<n;j++){
//             dp[n-1][j]= triangle[n-1][j];
//         }
//         for(int i=n-2;i>=0;i--){
//             for(int j=0;j<=i;j++){
//                 int down= triangle[i][j]+dp[i+1][j];
//                 int diag= triangle[i][j]+dp[i+1][j+1];
//                 dp[i][j]=min(down,diag);
//             }
//         }
//         return dp[0][0];
//     }
// };



// Memoization
// class Solution {
// public:
//     int cntmin(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
//         if(i==n-1) return triangle[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int down= triangle[i][j]+ cntmin(i+1,j,n,triangle,dp);
//         int diag= triangle[i][j]+ cntmin(i+1,j+1,n,triangle,dp);
        
//         return dp[i][j]= min(down,diag);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n= triangle.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         return cntmin(0,0,n,triangle,dp);
//     }
// };