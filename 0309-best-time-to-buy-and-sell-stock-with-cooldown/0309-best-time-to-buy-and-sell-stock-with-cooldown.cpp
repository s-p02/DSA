// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        
        // base case not required because already initialized to zero:
        
        // if it would have been required it would be:       
//         for(int buy=0;buy<=1;buy++){
//             dp[n][buy]=0;
//         }
        
        int profit;
        for(int ind= n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                    profit= max(0+dp[ind+1][0],
                               -prices[ind]+ dp[ind+1][1]);
                }
                else{
                        profit= max(0+dp[ind+1][1],prices[ind]+ dp[ind+2][0]);
                }  
                dp[ind][buy]= profit;
            }
        }
        
        return dp[0][0];
        
    }
};


// // Memoization
// class Solution {
// public:
//     int stock(int ind, int buy,vector<int>& prices,int n,vector<vector<int>>&dp){
//         if(ind>=n){
//             return 0;
//         }
        
//         if(dp[ind][buy]!=-1) return dp[ind][buy];
        
//         int profit;
//         if(buy==0){
//             profit= max(0+stock(ind+1,0,prices,n,dp),
//                        -prices[ind]+ stock(ind+1,1,prices,n,dp));
//         }
//         else{
//             profit= max(0+stock(ind+1,1,prices,n,dp),
//                        +prices[ind]+ stock(ind+2,0,prices,n,dp));
//         }
        
//         return dp[ind][buy]= profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n= prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return stock(0,0,prices,n,dp);
//     }
// };