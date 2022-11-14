// Tabulation
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n= nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        
        
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int maxi= INT_MIN;
                for(int k=i;k<=j;k++){
                    int ans= (nums[i-1]* nums[k]* nums[j+1])+ 
                       dp[i][k-1] +dp[k+1][j];
                    maxi= max(maxi,ans);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};



// Memoization
// class Solution {
// public:
//     int f(int i, int j, vector<int>& nums,vector<vector<int>>& dp){
//         // base case:
//         if(i>j){
//             return 0;
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
//         int maxi= INT_MIN;
//         for(int k=i;k<=j;k++){
//             int ans= (nums[i-1]* nums[k]* nums[j+1])+ f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
//             maxi= max(maxi,ans);
//         }
//         return dp[i][j]=maxi;
//     }
//     int maxCoins(vector<int>& nums) {
//         int n= nums.size();
//         nums.push_back(1);
//         nums.insert(nums.begin(),1);
//         vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
//         return f(1,n,nums,dp);
//     }
// };