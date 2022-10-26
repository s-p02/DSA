// Space optimization
class Solution {
public:
    bool subsetSum(vector<int>& nums, int target, int n){
        vector<bool> prev(target+1,false);
        
        // intitialize base case: if ind==0 && target== nums[0]
        if(nums[0]<= target) prev[nums[0]]= true;
        
        for(int ind=1;ind<n;ind++){
            vector<bool> curr(target+1,false);
            curr[0]= true;   // intitialize base case everytime: if target==0
            for(int k=1;k<=target;k++){
                //not pick
                bool notpick= prev[k];

                bool pick= false;
                if(nums[ind]<=k){
                    pick= prev[k-nums[ind]];
                }
                curr[k]= pick || notpick;          
            }
            prev= curr;
        }
        return prev[target];       
    }
    bool canPartition(vector<int>& nums) {
        int totSum=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            totSum+= nums[i];
        }
        
        if(totSum % 2==1) return false; // if TotalSum is odd
        
        int target= totSum/2;
        
        return subsetSum(nums, target,n);
    }
};



// // Tabulation
// class Solution {
// public:
//     bool subsetSum(vector<int>& nums, int target, int n){
//         vector<vector<bool>> dp(n, vector<bool>(target+1,false));
        
//         // intitialize base case: if target==0
//         for(int i=0;i<n;i++){
//             dp[i][0]= true;
//         }
        
//         // intitialize base case: if ind==0 && target== nums[0]
//         if(target == nums[0]) dp[0][nums[0]]= true;
        
//         for(int ind=1;ind<n;ind++){
//             for(int k=1;k<=target;k++){
//                 //not pick
//                 bool notpick= dp[ind-1][k];

//                 bool pick= false;
//                 if(nums[ind]<=k){
//                     pick= dp[ind-1][k-nums[ind]];
//                 }
//                 dp[ind][k]= pick || notpick;          
//             }
//         }
//         return dp[n-1][target];       
//     }
//     bool canPartition(vector<int>& nums) {
//         int totSum=0;
//         int n= nums.size();
//         for(int i=0;i<n;i++){
//             totSum+= nums[i];
//         }
        
//         if(totSum % 2==1) return false; // if TotalSum is odd
        
//         int target= totSum/2;
        
//         return subsetSum(nums, target,n);
//     }
// };


// Memoization

// class Solution {
// public:
    
//     bool subsetSum(int ind, int target,vector<int>& nums,vector<vector<int>> &dp){
//         if(target==0) return true;
        
//         if(ind==0){
//             if(nums[ind]==target) return true;
//             else return false;
//         }
        
//         if(dp[ind][target]!=-1) return dp[ind][target];
        
//         //not pick
        
//         bool notpick= subsetSum(ind-1,target, nums,dp);
        
//         bool pick= false;
//         if(nums[ind]<=target){
//             pick= subsetSum(ind-1, target-nums[ind], nums,dp);
//         }
        
//         return dp[ind][target]= pick || notpick;
//     }
//     bool canPartition(vector<int>& nums) {
//         int totSum=0;
//         int n= nums.size();
//         for(int i=0;i<n;i++){
//             totSum+= nums[i];
//         }
        
//         if(totSum % 2==1) return false; // if TotalSum is odd
        
//         int target= totSum/2;
        
//         vector<vector<int>> dp(n, vector<int>(target+1,-1));
        
//         return subsetSum(n-1,target, nums,dp);
//     }
// };


