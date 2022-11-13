class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,1);
        vector<int> ct(n,1);
        
        // TABULATION ALGO along with additional Count Table
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                // Longer LIS is found at index therefore count of lis at index i will be                   equal to count of lis at index j(prev)
                if(nums[i]>nums[j] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    ct[i]=ct[j];
                }
            //Same length LIS is found Therefore add the count of prev to current index
                else if(nums[i]>nums[j] && 1+dp[j]== dp[i]){
                    ct[i]=ct[i]+ct[j];
                }
            }
        }
        int maxi= INT_MIN;
        // finding the maximum value;
        for(int i=0;i<n;i++){
            maxi= max(maxi,dp[i]);
        }
        
        // Adding count of all elements having maximum value in dp table
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                ans+=ct[i];
            }
        }
        
        return ans;
        
        
        
    }
};