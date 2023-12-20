class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int a= prices[0];
        int b= prices[1];
        if(a+b<=money){
            return money-(a+b);
        }
        else
            return money;
    }
};