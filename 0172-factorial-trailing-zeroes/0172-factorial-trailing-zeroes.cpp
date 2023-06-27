// In log n solution count the number of 5's that will give the number of zeros
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt=0;
        while(n>0){
            n=n/5;
            cnt+= n;
        }
        return cnt;
    }
};



// It will not work


// class Solution {
// public:
//     int fact(int n, vector<int>&dp){
//         if(n<=1){
//             return n;
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         return dp[n]=fact(n-1,dp)+fact(n-2,dp);
//     }
//     int trailingZeroes(int n) {
//         vector<int> dp(n+1,-1);
//         int ans= fact(n,dp);
//         int cnt=0;
//         while(true){
//             if(ans%10==0){
//                 cnt++;
//             }
//             else{
//                 break;
//             }
//             ans=ans/10;
//         }
//         return cnt;
//     }
// };