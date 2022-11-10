class Solution {
public:
    bool jump(int ind, vector<int>& nums,vector<int> &dp){
        // base case
        if(ind==nums.size()-1){
            return true;
        }
        else if(ind > nums.size()-1){
            return false;
        }
        
        // Memoiztion:
        if(dp[ind]!=-1) return dp[ind];
        
        // recurrence:
        int maxjump= nums[ind];
        bool ans= false;
        for(int i=1;i<=maxjump;i++){
            ans=ans || jump(ind+i,nums,dp);
            if(ans==true){
                break;
            }
        }
        
        return dp[ind]= ans;
    }
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1,-1);
        return jump(0,nums,dp);
    }
};