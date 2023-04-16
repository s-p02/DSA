class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            int maxi=INT_MIN;
            for(int j=0;j<n;j++){
                string k= to_string(grid[j][i]);
                int digit=k.size();
                maxi=max(maxi,digit);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};