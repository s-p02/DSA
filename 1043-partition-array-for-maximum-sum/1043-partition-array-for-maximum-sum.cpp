// Tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
        vector<int> dp(n+1,0);
        
        // base Case:
        dp[n]=0;
        
        // Table
        for(int i=n-1;i>=0;i--){
            int largestSum= INT_MIN;
            int maxi= INT_MIN;
            for(int ind=i;ind<min(n,i+k);ind=ind+1){
                maxi= max(arr[ind],maxi); 
                int cnt= (ind-i+1)*maxi+ dp[ind+1];
                largestSum= max(largestSum,cnt);
            }
            dp[i]= largestSum;
        }
        return dp[0];    
    }
};




// // Memoization
// class Solution {
// public:
//     int f(int i,vector<int>& arr,int n, int k,vector<int>&dp){
//         // base case
//         if(i==n) return 0;
//         if(dp[i]!=-1) return dp[i];
//         int largestSum= INT_MIN;
//         int maxi= INT_MIN;
//         for(int ind=i;ind<min(n,i+k);ind=ind+1){
//             maxi= max(arr[ind],maxi); 
//             int cnt= (ind-i+1)*maxi+ f(ind+1,arr,n,k,dp) ;
//             largestSum= max(largestSum,cnt);
//         }
        
//         return dp[i]= largestSum;
        
//     }
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n= arr.size();
//         vector<int> dp(n,-1);
//         return f(0,arr,n,k,dp);
//     }
// };