// Tabulation Algorithm
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,1);
        for(int ind=0;ind<n;ind++){
            for(int prev=0;prev<ind;prev++){
                if(nums[prev]<nums[ind]){
                    dp[ind]=max(dp[ind], 1+dp[prev]);
                }
            }
        }
        
        // maximum form the dp array:
        int ans= INT_MIN;
        for(int i=0;i<n;i++){
            ans= max(ans,dp[i]);
        }
        
        return ans;
    }
};





// // Tabulation
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n= nums.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
//         // NO need for base case because already entire dp is initialized to 0
        
//         for(int ind=n-1;ind>=0;ind--){
//             for(int prev_ind=n-1;prev_ind>=-1;prev_ind--){
                
//                 int notpick= 0+ dp[ind+1][prev_ind+1];
//                 int pick= INT_MIN;
//                 if(prev_ind == -1|| nums[ind]>nums[prev_ind]  ){
//                     pick= 1+ dp[ind+1][ind+1];
//                 }

//                 dp[ind][prev_ind+1]=max(pick,notpick);
//             }
//         }
        
//         return dp[0][-1+1];
//     }
// };


// // Memoization
// class Solution {
// public:
//     int lis(int ind,int prev_ind,vector<int>& nums,vector<vector<int>> &dp){
//         if(ind==nums.size()){
//             return 0;
//         }
        
//         if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        
//         int notpick= 0+ lis(ind+1,prev_ind,nums,dp);
//         int pick= INT_MIN;
//         if(prev_ind == -1|| nums[ind]>nums[prev_ind]  ){
//             pick= 1+ lis(ind+1,ind,nums,dp);
//         }
        
//         return dp[ind][prev_ind+1]=max(pick,notpick);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n= nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         return lis(0,-1,nums,dp);
//     }
// };
