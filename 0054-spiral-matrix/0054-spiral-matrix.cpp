class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        int left=0;
        int right= m-1;
        int top=0;
        int bottom= n-1;
        vector<int> ans;
        while(left<=right && top<=bottom){
            // fill top row
            for(int i=left;i<=right;i++){
                ans.push_back(mat[top][i]);  
            }
            top++;
            
            // fill right col
            for(int i=top;i<=bottom;i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            
            if(top<=bottom){   
            // fill bottom row in rev order
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
           
            }
           
            if(left<=right){
            // fill left col in rev order
            for(int i=bottom;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
            }
            
        }
        return ans;
    }
};