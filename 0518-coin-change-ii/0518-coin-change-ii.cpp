class Solution {
public:
    int count(int ind, int tar,vector<int>& nums,vector<vector<int>>&dp){
        if(ind==0){
            if(tar%nums[0]==0) return 1;
            else return 0;
        }
        
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        
        int notpick= count(ind-1, tar,nums,dp);
        int pick=0;
        if(nums[ind]<=tar){
            pick= count(ind,tar-nums[ind],nums,dp);
        }
        return dp[ind][tar]= pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return count(n-1,amount,coins,dp);
    }
};