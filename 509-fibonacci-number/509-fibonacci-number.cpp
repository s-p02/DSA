class Solution {
public:
    // memoization
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return recur(n,dp);
    }
    int recur(int n, vector<int>& dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= recur(n-1,dp)+recur(n-2,dp);
    }
};