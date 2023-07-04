class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        int ans= recur(nums.size()-1,nums,dp);
        return ans;
    }
    int recur(int ind, vector<int>& nums, vector<int>&dp){
        if(ind<0){
            return 0;
        }
        if(ind==0){
            return nums[ind];
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        //pick
        int pick= nums[ind]+ recur(ind-2,nums,dp);
        
        //notpick
        int notpick= recur(ind-1,nums,dp);
        return dp[ind]=max(pick, notpick);
    }
};