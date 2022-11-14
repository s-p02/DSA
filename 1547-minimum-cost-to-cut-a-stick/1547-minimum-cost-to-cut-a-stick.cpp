// Tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        
        sort(cuts.begin(),cuts.end());
        int c= cuts.size(); // size has been increased by 2 because we have added elements at 0th position and last position
        
        vector<vector<int>> dp(c+1,vector<int>(c+1,0));
        
        for(int i= c-2;i>=1;i--){
            for(int j= 1;j<=c-2;j++){
                if(i>j) continue;
                
                int mini = INT_MAX;
                for(int ind=i; ind<=j; ind++){

                    int ans = cuts[j+1] - cuts[i-1] +
                                dp[i][ind-1] +
                               dp[ind+1][j];

                    mini = min(mini, ans);

                }
                dp[i][j]= mini;
            }
        }
        
        return dp[1][c-2];
    }
};


//  //Memoization:
// class Solution {
// public:
   
//     int f(int i, int j, vector<int> &cuts,  vector<vector<int>> &dp){
//         // base case
//         if(i>j)
//             return 0;

//         if(dp[i][j]!=-1)
//             return dp[i][j];

//         int mini = INT_MAX;

//         for(int ind=i; ind<=j; ind++){

//             int ans = cuts[j+1] - cuts[i-1] +
//                         f(i,ind-1,cuts,dp) +
//                         f(ind+1,j,cuts,dp);

//             mini = min(mini, ans);

//         }

//         return dp[i][j] = mini;
//     }
    
//     int minCost(int n, vector<int>& cuts) {
        
//         cuts.push_back(n);
//         cuts.insert(cuts.begin(),0);
        
//         sort(cuts.begin(),cuts.end());
//         int c= cuts.size(); // size has been increased by 2 because we have added elements at 0th position and last position
        
//         vector<vector<int>> dp(c,vector<int>(c,-1));
//         // here we want pass from 0th index to last index of cuts but size has been increased by 2 because we have added elements at 0th position and last position therefore we pass values accordingly. 
//         return f(1,c-2,cuts,dp);
        
        
//     }
// };