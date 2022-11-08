// Memoization

class Solution {
public:
    int maxi(int ind, int buy, vector<int>&prices, int n,vector<vector<int>>&dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit;
        if(buy==0){
            profit= max(0+maxi(ind+1,0,prices,n,dp),
                       -prices[ind]+ maxi(ind+1,1,prices,n,dp));
        }
        else{
            profit= max(0+maxi(ind+1,1,prices,n,dp),
                       prices[ind]+ maxi(ind+1,0,prices,n,dp));
        }
        
        return dp[ind][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return maxi(0,0,prices,n,dp); 
    }
};