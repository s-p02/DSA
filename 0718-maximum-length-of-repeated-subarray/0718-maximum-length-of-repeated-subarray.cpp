class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //base Case:
        for(int i=0;i<=m;i++){   // if(index1==0 then index2 ranges from 0 to m)
            dp[0][i]=0;
        }
        
        for(int i=0;i<=n;i++){  // if(index2==0 then index1 ranges from 0 to n)
            dp[i][0]=0;
        }
        
        // table
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]= 1+ dp[i-1][j-1];
                    ans= max(ans, dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
};