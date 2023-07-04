class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans= recur(n,dp);
        return ans;
    }
    int recur(int n,vector<int> &dp){
        if(n==0 || n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int onestep= recur(n-1,dp);
        int twostep= recur(n-2,dp);
        return dp[n]= onestep+twostep;
    }
};
