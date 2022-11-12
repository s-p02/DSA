class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n= nums.size();
        
        
        // sort:
        sort(nums.begin(),nums.end());
        
        vector<int>dp(n,1);
        vector<int>hash(n,1);
        
        // Filling the values of DP array with TABULATION Algorithm:
        
        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int prev=0;prev<ind;prev++){
                if(nums[ind] % nums[prev] ==0 && 1 + dp[prev] > dp[ind]){
                    dp[ind]= 1+dp[prev];
                    hash[ind]=prev;
                }
            }
        }
        
        // Finding the maximum of Dp array
        
        int ans=-1;
        int lastind=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                lastind=i;
            }
        }
            
        // backtracking to find the elements of Dp
        
        vector<int> temp;
        temp.push_back(nums[lastind]);
        
        while(hash[lastind] != lastind){
            lastind= hash[lastind];
            temp.push_back(nums[lastind]);
        }
        return temp;     
      }
};