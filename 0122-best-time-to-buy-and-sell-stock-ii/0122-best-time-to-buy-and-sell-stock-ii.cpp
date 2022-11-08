// Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<int>ahead(2,0);
        
        ahead[0]=0;
        ahead[1]=0;
        
        int profit;
        
        // table
        for(int ind=n-1;ind>=0;ind--){
            vector<int>curr(2,0);
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                    profit= max(0+ahead[0],-prices[ind]+ ahead[1]);
                }
                else{
                    profit= max(0+ahead[1],prices[ind]+ ahead[0]);
                }
                curr[buy]=profit;
            }
            ahead= curr;
        }
        return ahead[0];
    }
};





// // Tabulation
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n= prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(2,0));
        
//         dp[n][0]=0;
//         dp[n][1]=0;
        
//         int profit;
        
//         // table
//         for(int ind=n-1;ind>=0;ind--){
//             for(int buy=0;buy<=1;buy++){
//                 if(buy==0){
//                     profit= max(0+dp[ind+1][0],-prices[ind]+ dp[ind+1][1]);
//                 }
//                 else{
//                     profit= max(0+dp[ind+1][1],prices[ind]+ dp[ind+1][0]);
//                 }
//                 dp[ind][buy]=profit;
//             }
//         }
//         return dp[0][0];
//     }
// };

// // Memoization

// class Solution {
// public:
//     int maxi(int ind, int buy, vector<int>&prices, int n,vector<vector<int>>&dp){
//         if(ind==n){
//             return 0;
//         }
//         if(dp[ind][buy]!=-1) return dp[ind][buy];
//         int profit;
//         if(buy==0){
//             profit= max(0+maxi(ind+1,0,prices,n,dp),
//                        -prices[ind]+ maxi(ind+1,1,prices,n,dp));
//         }
//         else{
//             profit= max(0+maxi(ind+1,1,prices,n,dp),
//                        prices[ind]+ maxi(ind+1,0,prices,n,dp));
//         }
        
//         return dp[ind][buy]= profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n= prices.size();
//         vector<vector<int>>dp(n,vector<int>(2,-1));
//         return maxi(0,0,prices,n,dp); 
//     }
// };