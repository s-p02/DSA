class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n= s1.size();
        int m= s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // base case:
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int j=0;j<=n;j++){
            dp[j][0]=0;
        }
        // table
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int lcslen= dp[n][m];
        // if we need to find the length of Shortest common Subsequence:
        int scslen= n+m-lcslen;
        
        // if we want to print the scs then we use the dp table:
        int i=n;
        int j=m;
        string ans="";
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+= s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+= s1[i-1];
                i--;
            }
            else{
                ans+=s2[j-1];
                j--;
            }
        }
        // Adding remaining elements if remaining:
        while(i>0){
            ans+=s1[i-1];
            i--;
        }
        while(j>0){
            ans+=s2[j-1];
            j--;
        }
        
        // Final result is the reverse of ans string
        reverse(ans.begin(),ans.end());
        return ans;
    }
};