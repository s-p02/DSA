// Tabulation
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n= s1.size();
        int m= s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        // base case with shifting of index
        for(int j=0;j<=m;j++){ // when i==0
            dp[0][j]=j;
        }
        for(int i=0;i<=n;i++){ // when j==0
            dp[i][0]=i;
        }
        
        // table
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=0+dp[i-1][j-1];
                }
                else{
                    int insert= 1+dp[i][j-1];
                    int del= 1+ dp[i-1][j]; 
                    int replace= 1+ dp[i-1][j-1];
                    dp[i][j]= min(insert,min(del,replace));
                }
            }
        }
        return dp[n][m];        
    }
};


// Memoization
// class Solution {
// public:
//     int f(int i, int j, string &s1, string &s2, vector<vector<int>>& dp){
//         if(i<0){
//             return j+1;
//         }
//         if(j<0){
//             return i+1;
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         if(s1[i]==s2[j]){
//             return dp[i][j]= 0+ f(i-1,j-1,s1,s2,dp);
//         }
//         else{
//             int insert= 1+f(i,j-1,s1,s2,dp);
//             int del= 1+ f(i-1,j,s1,s2,dp);
//             int replace= 1+ f(i-1,j-1,s1,s2,dp);
//             return dp[i][j]= min(insert,min(del,replace));
//         }
//     }
//     int minDistance(string word1, string word2) {
//         int n= word1.size();
//         int m= word2.size();
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         return f(n-1,m-1,word1,word2,dp);
//     }
// };