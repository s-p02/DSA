// Memoization
class Solution {
public:
    int mincost(int ind, int day,vector<int>& days,vector<int>& costs,vector<vector<int>> &dp){
        
        //base case:
        if(ind==days.size()){
            return 0;
        }
        
        // memoization
        if(dp[ind][day]!=-1) return dp[ind][day];
        
        // recurrence:
        int cost;
        if(days[ind]<=day){
            cost= 0+mincost(ind+1,day,days,costs,dp);
        }
        else{
            int oneday= costs[0]+mincost(ind+1,days[ind],days,costs,dp);
            int sevendays= costs[1]+ mincost(ind+1,days[ind]+6,days,costs,dp);
            int monthpass= costs[2]+ mincost(ind+1,days[ind]+29,days,costs,dp);
            cost= min(oneday, min(sevendays,monthpass));
        }
        
        return dp[ind][day]= cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n= days.size();
        vector<vector<int>> dp(n,vector<int>(730,-1));
        return mincost(0,0,days,costs,dp);
        
    }
};