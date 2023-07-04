// Recursion Brute
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        int ans= recur(0,s,dp);
        return ans;
    }
    int recur( int ind, string s,vector<int> &dp){
        if(ind==s.size()){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int chooseOne=0;
        int ch1= s[ind]-'0';
        int ch2;
        if(ind+1<s.size()){
            ch2= s[ind+1]-'0';
        }
        if(ch1!=0){
             chooseOne= recur(ind+1,s,dp);
        }
        int chooseTwo=0;
        if(ind+1<s.size()){
            if(ch1==1 ){
                chooseTwo=recur(ind+2,s,dp);
            }
            else if(ch1==2 && ch2<=6){
                chooseTwo=recur(ind+2,s,dp);
            }
        }
        return dp[ind]=chooseOne+chooseTwo;
           
    }
    
};