// Combinatrics Solution:
class Solution {
public:
    int uniquePaths(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
    
};

// // Dynamic Programming Solution
// class Solution {
// public:
//     int uniquePaths(int row, int col) {
//         vector<vector<int>> dp(row,vector<int>(col,-1));
//         int num=countPaths(0,0,row,col,dp);
//         // if(row==1&&col==1)
//         //     return num;
//         return num;
//     }
    
//     int countPaths(int i,int j,int row,int col,vector<vector<int>> &dp)
//     {
//         if(i==(row-1)&&j==(col-1)) return 1;
//         if(i>=row||j>=col) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//      else {
//          dp[i][j]=countPaths(i+1,j,row,col,dp)+countPaths(i,j+1,row,col,dp);
//          return dp[i][j];
//      }
        
        
//     }
// };

// // Recursive Solution:
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         return countPaths(0,0,m,n);
//     }
//     int countPaths(int i,int j, int m, int n){
//         if(i>=m || j>=n){
//             return 0;
//         }
//         if(i==(m-1) && j==(n-1)){
//             return 1;
//         }
//         else{
//             return countPaths(i+1,j,m,n)+countPaths(i,j+1,m,n);
//         }
//     }
// };