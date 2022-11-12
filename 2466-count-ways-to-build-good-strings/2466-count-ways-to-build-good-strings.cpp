class Solution {
public:
    const int modu= 1e9+7;
    long long cnt(int zero, int one,int n, vector<long long> &dp){
        
        if(n==0) return 1;
        
        if(n<0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        long long count=0;
        count = count+ cnt(zero, one,n-zero,dp);
        count = count+ cnt(zero,one,n-one,dp);
        
        return dp[n]=count % modu;
    
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high+1,-1);
        long long ans=0;
        for(int i=low;i<=high;i++){
            ans=((ans %modu)+ (cnt(zero,one,i,dp) %modu)) % modu ;
        }
        return ans;
    }
};