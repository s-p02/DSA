class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        int left=0;
        int right= n-1;
        int top=0;
        int bottom= n-1;
        int val=1;
        while(left<=right){
            // fill top row
            for(int i=left;i<=right;i++){
                mat[top][i]=val;
                val++;
            }
            top++;
            
            // fill right col
            for(int i=top;i<=bottom;i++){
                mat[i][right]=val;
                val++;
            }
            right--;
            
            // fill bottom row in rev order
            for(int i=right;i>=left;i--){
                mat[bottom][i]=val;
                val++;
            }
            bottom--;
           
            
            // fill left col in rev order
            for(int i=bottom;i>=top;i--){
                mat[i][left]=val;
                val++;
            }
            left++;
            
        }
        return mat;
    }
};