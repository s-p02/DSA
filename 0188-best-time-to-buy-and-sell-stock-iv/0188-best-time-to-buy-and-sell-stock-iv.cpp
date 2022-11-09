class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n= prices.size();
        vector<vector<int>> ahead(2,vector<int>(k+1,0));
                                                         
        // Base case already intitialized while declaring dp
        
        // table
        for(int ind=n-1;ind>=0;ind--){ // ind==n base case
             vector<vector<int>> curr(2,vector<int>(k+1,0));
            for(int buy=1;buy>=0;buy--){
                for(int cap=k;cap>0;cap--){ //cap==0 base case
                    if(buy==0){
                        curr[buy][cap]= max(0+ ahead[0][cap],
                                  -prices[ind]+ ahead[1][cap]);
                    }
                    else{
                        curr[buy][cap]=max(0+ ahead[1][cap],
                                  +prices[ind]+ ahead[0][cap-1]);
                    }                    
                }
            }
            ahead= curr;
        }
        return ahead[0][k];
        
    }
};