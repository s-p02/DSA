// Space Optimization
class Solution {
public:
    bool isMatch(string s, string p) {
        int n= s.size();
        int m= p.size();
        vector<bool>prev(m+1,false);
        
        // base case with 1 based indexing:
        prev[0]= true;    //if(i<0 && j<0)
        
        // This base case is implemented while operating on curr
        
        // for(int i=1;i<=n;i++){ //if(j<0 && i>=0) return false;
        //     dp[i][0]=false;
        // }
        
        for(int j=1; j<=m;j++){ //if(i<0 && j>=0)
            bool flag=true;
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*') flag=false;
            }
            prev[j]= flag;
        }
        
        for(int i=1;i<=n;i++){
            vector<bool>curr(m+1,false);
            curr[0]=false;
            for(int j=1;j<=m;j++){
                
               if(s[i-1]== p[j-1] || p[j-1]=='?'){
                    curr[j]= prev[j-1];
                }
                else{
                    if(p[j-1]=='*'){
                        curr[j]= prev[j] || curr[j-1];
                    }
                    else{
                        curr[j]= false;
                    }
                } 
            }
            prev=curr;
        }     
        return prev[m];       
    }
};


// // Tabulation
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int n= s.size();
//         int m= p.size();
//         vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        
//         // base case with 1 based indexing:
//         dp[0][0]= true;    //if(i<0 && j<0)
        
//         for(int i=1;i<=n;i++){ //if(j<0 && i>=0) return false;
//             dp[i][0]=false;
//         }
        
//         for(int j=1; j<=m;j++){ //if(i<0 && j>=0)
//             bool flag=true;
//             for(int k=1;k<=j;k++){
//                 if(p[k-1]!='*') flag=false;
//             }
//             dp[0][j]= flag;
//         }
        
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
                
//                if(s[i-1]== p[j-1] || p[j-1]=='?'){
//                     dp[i][j]= dp[i-1][j-1];
//                 }
//                 else{
//                     if(p[j-1]=='*'){
//                         dp[i][j]= dp[i-1][j] || dp[i][j-1];
//                     }
//                     else{
//                         dp[i][j]= false;
//                     }
//                 } 
//             }
//         }     
//         return dp[n][m];       
//     }
// };


// Memoization
// class Solution {
// public:
//     bool match(int i, int j, string &s, string &p,vector<vector<int>>&dp)
//     {
//         if(i<0 && j<0) return true;
        
//         if(j<0 && i>=0) return false;
        
//         if(i<0 && j>=0){
//             for(int k=0;k<=j;k++){
//                 if(p[k]!='*') return false;
//             }
//             return true;
//         }
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         if(s[i]== p[j] || p[j]=='?'){
//             return dp[i][j]=match(i-1,j-1,s,p,dp);
//         }
//         else{
//             if(p[j]=='*'){
//                 return dp[i][j]= match(i,j-1,s,p,dp) || match(i-1,j,s,p,dp);
//             }
//             else{
//                 return dp[i][j]= false;
//             }
//         }
        
//     }
//     bool isMatch(string s, string p) {
//         int n= s.size();
//         int m= p.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return match(n-1,m-1,s,p,dp);
        
//     }
// };