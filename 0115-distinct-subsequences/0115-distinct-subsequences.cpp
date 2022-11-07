// Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        // Shifting of indexes because -1 index is not possible in table
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        
        // base case:
        for(int i=0;i<=n;i++){ // ifj==0 then i can range from 0 to n
            dp[i][0]=1;
        }
        for(int j=1;j<=m;j++){ // ifi==0 then j can range from 1 to m
            dp[0][j]=0;
        }
        
        // table
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]= dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};


// // Memoization
// class Solution {
//     int f(int i, int j,string &s, string& t, vector<vector<int>>&dp){
//         if(j<0){
//             return 1;
//         }
//         if(i<0){
//             return 0;
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         if(s[i]==t[j]){
//             return dp[i][j]= f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
//         }
//         else{
//             return dp[i][j]=f(i-1,j,s,t,dp);
//         }
        
//     }
// public:
//     int numDistinct(string s, string t) {
//         int n= s.size();
//         int m= t.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return f(n-1,m-1,s,t,dp);
//     }
// };