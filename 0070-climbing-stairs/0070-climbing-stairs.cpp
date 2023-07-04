// Tabulation
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+2,-1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            int onestep= dp[i-1];
            int twostep= dp[i-2];
            dp[i]= onestep+twostep;
        }
        return dp[n];
    }
};


// Memoization

// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n+1,-1);
//         int ans= recur(n,dp);
//         return ans;
//     }
//     int recur(int n,vector<int> &dp){
//         if(n==1) return 1;
//         if(n==2) return 2;
            
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         int onestep= recur(n-1,dp);
//         int twostep= recur(n-2,dp);
//         return dp[n]= onestep+twostep;
//     }
// };
