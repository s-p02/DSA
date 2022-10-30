// Space Optimization
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();
        //Applying Shifting of indexes in order to represent -1
        vector<int>prev(m+1,0);
        
        // base case
        for(int i=0;i<=m;i++){   // if(ind1==0) then ind2 can go from 0 to m
            prev[i]=0;
        }
        
        // Table
        for(int i=1;i<=n;i++){
            vector<int>curr(m+1,0);
            curr[0]=0;
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]= 1+ prev[j-1];
                }
                else{ // if not matched
                    curr[j]=0+ max(curr[j-1],prev[j]);
                }
            }
            prev=curr;
        }
        
        return prev[m];
    }
};


// // Tabulation
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n= text1.size();
//         int m= text2.size();
//         //Applying Shifting of indexes in order to represent -1
//         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
//         // base case
//         for(int i=0;i<=m;i++){   // if(ind1==0) then ind2 can go from 0 to m
//             dp[0][i]=0;
//         }
        
//         for(int j=0;j<=n;j++){   // if(ind2==0) then ind1 can go from 0 to n
//             dp[j][0]=0;
//         }
        
//         // Table
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(text1[i-1]==text2[j-1]){
//                     dp[i][j]= 1+ dp[i-1][j-1];
//                 }
//                 else{ // if not matched
//                     dp[i][j]=0+ max(dp[i][j-1],dp[i-1][j]);
//                 }
//             }
//         }
        
//         return dp[n][m];
//     }
// };


// Memoization
// class Solution {
// public:
//     int f(int i, int j, string &s1, string&s2, vector<vector<int>>&dp){
//         if(i<0||j<0){
//             return 0;
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         // if matched
//         if(s1[i]==s2[j]){
//             return dp[i][j]= 1+ f(i-1,j-1,s1,s2,dp);
//         }
//         else{ // if not matched
//             return dp[i][j]=0+ max(f(i,j-1,s1,s2,dp),f(i-1,j,s1,s2,dp));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n= text1.size();
//         int m= text2.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return f(n-1,m-1,text1,text2,dp);
//     }
// };