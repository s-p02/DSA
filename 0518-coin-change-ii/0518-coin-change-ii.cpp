// Space optimization
class Solution {
public:
    int change(int amount, vector<int>& nums) {
        
        int n= nums.size();
        vector<int>prev(amount+1,0);
        
        // base cases:
        for(int i=0;i<=amount;i++){
            if(i%nums[0]==0) prev[i]=1;
        }
        
        for(int ind=1;ind<n;ind++){
            vector<int>curr(amount+1,0);
            for(int tar=0;tar<=amount;tar++){
                int notpick= prev[tar];
                int pick=0;
                if(nums[ind]<=tar){
                    pick= curr[tar-nums[ind]];
                }
                curr[tar]= pick+notpick;
            }
            prev=curr;
        }
        
        return prev[amount];
        
    }
};


// // Tabulation
// class Solution {
// public:
//     int change(int amount, vector<int>& nums) {
        
//         int n= nums.size();
//         vector<vector<int>>dp(n, vector<int>(amount+1,0));
        
//         // base cases:
//         for(int i=0;i<=amount;i++){
//             if(i%nums[0]==0) dp[0][i]=1;
//         }
        
//         for(int ind=1;ind<n;ind++){
//             for(int tar=0;tar<=amount;tar++){
//                 int notpick= dp[ind-1][tar];
//                 int pick=0;
//                 if(nums[ind]<=tar){
//                     pick= dp[ind][tar-nums[ind]];
//                 }
//                 dp[ind][tar]= pick+notpick;
//             }
//         }
        
//         return dp[n-1][amount];
        
//     }
// };


// memoization
// class Solution {
// public:
//     int count(int ind, int tar,vector<int>& nums,vector<vector<int>>&dp){
//         if(ind==0){
//             if(tar%nums[0]==0) return 1;
//             else return 0;
//         }
        
//         if(dp[ind][tar]!=-1) return dp[ind][tar];
        
//         int notpick= count(ind-1, tar,nums,dp);
//         int pick=0;
//         if(nums[ind]<=tar){
//             pick= count(ind,tar-nums[ind],nums,dp);
//         }
//         return dp[ind][tar]= pick+notpick;
//     }
//     int change(int amount, vector<int>& coins) {
//         int n= coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1,-1));
//         return count(n-1,amount,coins,dp);
//     }
// };