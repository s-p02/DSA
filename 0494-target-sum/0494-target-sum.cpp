class Solution {
public:
    int count(int ind, int tar,vector<int>& nums, int n){
        
        vector<vector<int>>dp(n,vector<int>(tar+1,0));
        
        // base Cases:
        if(nums[0]==0) dp[0][0]=2;
        else{
            dp[0][0]=1;
        }
        if(nums[0]!=0 && nums[0]<= tar) dp[0][nums[0]]=1;
        
        // table
        
        for(int ind=1;ind<n;ind++){
            for(int k=0;k<=tar;k++){
                
                int notpick= dp[ind-1][k];
                int pick=0;
                if(nums[ind]<= k){
                    pick= dp[ind-1][k- nums[ind]];
                }
                dp[ind][k]= pick+notpick;
            }
        }
        return dp[n-1][tar];
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        // Make the question similar to Count partitions with given difference D
        
        int n= nums.size();
        int totSum=0;
        for(int i=0;i<n;i++){
            totSum+=nums[i];
        }
        
        if(totSum-target<0 || (totSum-target)%2 != 0) return 0;
        else{
            int modifiedTar= (totSum- target)/2;
            return count(n-1, modifiedTar ,nums,n);
        }
    }
};

// // Memoization
// class Solution {
// public:
//     int count(int ind, int target,vector<int>& nums, vector<vector<int>> &dp){
//         if(ind==0){
//             if(target==0 && nums[0]==0) return 2;
//             if(target==0 || target==nums[0]) return 1;
//             return 0;
//         }
        
//         if(dp[ind][target]!=-1) return dp[ind][target];
        
//         int notpick= count(ind-1,target, nums,dp);
//         int pick=0;
//         if(nums[ind]<= target){
//             pick= count(ind-1, target- nums[ind], nums ,dp);
//         }
        
//         return dp[ind][target]= pick+notpick;
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         // Make the question similar to Count partitions with given difference D
        
//         int n= nums.size();
//         int totSum=0;
//         for(int i=0;i<n;i++){
//             totSum+=nums[i];
//         }
        
//         if(totSum-target<0 || (totSum-target)%2 != 0) return 0;
//         else{
//             int modifiedTar= (totSum- target)/2;
//             vector<vector<int>>dp(n,vector<int>(modifiedTar+1,-1));
//             return count(n-1, modifiedTar ,nums,dp);
//         }
//     }
// };