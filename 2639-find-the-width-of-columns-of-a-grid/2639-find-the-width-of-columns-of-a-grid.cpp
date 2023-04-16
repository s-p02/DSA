class Solution {
public:
    int digits(int num){
        if(num==0){
            return 1;
        }
        int n=num;
        int cnt=0;
        while(num>0){
            num=num/10;
            cnt++;
        }
        return cnt;
    }
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            int maxi=INT_MIN;
            for(int j=0;j<n;j++){
                int digit=0;
                if(grid[j][i]<0){
                    digit=1;
                    int nele=grid[j][i]*-1;
                    digit+=digits(nele);
                }
                else{
                    digit+= digits(grid[j][i]);
                }
                maxi=max(maxi,digit);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};