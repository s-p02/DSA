//Space Optimzation
class Solution {
public:
    int f(vector<int>& coins, int target){
        int n= coins.size();
        vector<int> prev(target+1,0);
        // Base case 
        for(int i=0; i<= target;i++){
            if(i%coins[0]==0) prev[i]= i/coins[0];
            else prev[i]= 1e9;
        }
        
        for(int ind=1;ind<n;ind++){
            vector<int> curr(target+1,0);
            for(int tar=0;tar<=target;tar++){
                int notpick= 0+ prev[tar];
                int pick= 1e9; 
                if(coins[ind]<= tar) {
                    pick= 1+ curr[tar-coins[ind]];
                }
                curr[tar]= min(pick,notpick);
            }
            prev= curr;
        }
        return prev[target];
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans= f(coins,amount);
        if(ans>=1e9){
            return -1;
        }
        else{
            return ans;
        }
    }
};


// //Tabulation
// class Solution {
// public:
//     int f(vector<int>& coins, int target){
//         int n= coins.size();
//         vector<vector<int>>dp(n,vector<int>(target+1,0));
        
//         // Base case 
//         for(int i=0; i<= target;i++){
//             if(i%coins[0]==0) dp[0][i]= i/coins[0];
//             else dp[0][i]= 1e9;
//         }
        
//         for(int ind=1;ind<n;ind++){
//             for(int tar=0;tar<=target;tar++){
//                 int notpick= 0+ dp[ind-1][tar];
//                 int pick= 1e9; 
//                 if(coins[ind]<= tar) {
//                     pick= 1+ dp[ind][tar-coins[ind]];
//                 }
//                 dp[ind][tar]= min(pick,notpick);
//             }
//         }
//         return dp[n-1][target];
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int ans= f(coins,amount);
//         if(ans>=1e9){
//             return -1;
//         }
//         else{
//             return ans;
//         }
//     }
// };

// // Memoization 
// class Solution {
// public:
//     int f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
//         if(ind==0){
//             if(target% nums[0]==0) return target/nums[0];
//             else return 1e9;
//         }
        
//         if(dp[ind][target]!=-1) return dp[ind][target];
        
//         int notpick= 0+ f(ind-1,target,nums,dp);
//         int pick= INT_MAX;
//         if(nums[ind]<=target){
//             pick= 1+ f(ind,target-nums[ind],nums,dp);
//         }
//         return dp[ind][target]= min(pick,notpick);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n= coins.size();
//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
//         int ans= f(n-1,amount, coins,dp);
//         if(ans>=1e9){
//             return -1;
//         }
//         else{
//             return ans;
//         }
//     }
// };