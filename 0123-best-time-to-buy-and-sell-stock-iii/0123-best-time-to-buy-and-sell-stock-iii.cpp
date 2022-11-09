// Tablulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n+1,
                                      vector<vector<int>>(2,
                                                         vector<int>(3,0)));
        
        // Base case already intitialized while declaring dp
        
        // table
        for(int ind=n-1;ind>=0;ind--){ // ind==n base case
            for(int buy=1;buy>=0;buy--){
                for(int cap=2;cap>0;cap--){ //cap==0 base case
                    if(buy==0){
                        dp[ind][buy][cap]= max(0+ dp[ind+1][0][cap],
                                  -prices[ind]+ dp[ind+1][1][cap]);
                    }
                    else{
                        dp[ind][buy][cap]=max(0+ dp[ind+1][1][cap],
                                  +prices[ind]+ dp[ind+1][0][cap-1]);
                    }
                    
                }
            }
        }
        return dp[0][0][2];       
    }
}; 




// memoization
// int stock(int ind, int buy, int cap,vector<int>& prices, int n,vector<vector<vector<int>>> &dp ){
//     if(ind==n || cap==0){
//         return 0;
//     }
//     if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
    
//     if(buy==0){
//         return dp[ind][buy][cap]= max(0+ stock(ind+1,0,cap,prices,n,dp),
//                   -prices[ind]+ stock(ind+1,1,cap,prices,n,dp));
//     }
//     else{
//         return dp[ind][buy][cap]=max(0+ stock(ind+1,1,cap,prices,n,dp),
//                   +prices[ind]+ stock(ind+1,0,cap-1,prices,n,dp));
//     }
// }
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n= prices.size();
//         vector<vector<vector<int>>> dp(n,
//                                       vector<vector<int>>(2,
//                                                          vector<int>(3,-1)));
//         return stock(0,0,2,prices,n,dp);
//     }
// };