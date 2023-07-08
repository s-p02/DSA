class Solution {
public:
  long long recur(int ind,vector<int>& arr, int n,vector<int>&dp){
          if(ind==n-1){
              return 0;
          }
          if(ind>n-1){
              return 1e9;
          }
          if(dp[ind]!=-1) return dp[ind];
          int possible= arr[ind];
          long long mini= INT_MAX;
          for(int i=1;i<=possible;i++){
              long long ans=1e9;
              if(ind+i<n){
                  ans=1+recur(ind+i,arr,n,dp);
              }
              mini= min(mini,ans);
          }
          return dp[ind]=mini;
    }
    
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int n= nums.size();
        vector<int>dp(n+1,-1);
        int ans= recur(0,nums,n,dp);
        return ans;
    }
};