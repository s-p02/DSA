// Memoization 
class Solution {
public:
    int f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(ind==0){
            if(target% nums[0]==0) return target/nums[0];
            else return 1e9;
        }
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int notpick= 0+ f(ind-1,target,nums,dp);
        int pick= INT_MAX;
        if(nums[ind]<=target){
            pick= 1+ f(ind,target-nums[ind],nums,dp);
        }
        return dp[ind][target]= min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= f(n-1,amount, coins,dp);
        if(ans>=1e9){
            return -1;
        }
        else{
            return ans;
        }
    }
};