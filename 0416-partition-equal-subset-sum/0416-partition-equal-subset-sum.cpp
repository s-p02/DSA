class Solution {
public:
    
    bool subsetSum(int ind, int target,vector<int>& nums,vector<vector<int>> &dp){
        if(target==0) return true;
        
        if(ind==0){
            if(nums[ind]==target) return true;
            else return false;
        }
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        //not pick
        
        bool notpick= subsetSum(ind-1,target, nums,dp);
        
        bool pick= false;
        if(nums[ind]<=target){
            pick= subsetSum(ind-1, target-nums[ind], nums,dp);
        }
        
        return dp[ind][target]= pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int totSum=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            totSum+= nums[i];
        }
        
        if(totSum % 2==1) return false; // if TotalSum is odd
        
        int target= totSum/2;
        
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        
        return subsetSum(n-1,target, nums,dp);
    }
};