class Solution {
public:
    bool ispalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,int n,string &s,vector<int> &dp){
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int mini= INT_MAX;
        for(int j=i;j<s.size();j++){
            if(ispalindrome(s,i,j)){
                int cuts= 1+f(j+1,n,s,dp);
                mini= min(mini,cuts);
            }
        }
        
        return dp[i]=mini;
        
    }
    int minCut(string s) {
        int n= s.size();
        vector<int> dp(n,-1);
        return f(0,n,s,dp)-1;
        
    }
};