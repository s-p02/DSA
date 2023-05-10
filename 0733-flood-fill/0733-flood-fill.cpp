class Solution {
public:
    void dfs(int row, int col,vector<vector<int>>& image, int newColor, int delRow[], int delCol[],
     int iniColor) {
        if(row<0||row>=image.size()|| col<0||col>=image[0].size()||image[row][col]!=iniColor|| 
           image[row][col]==newColor){
            return;
        }
        image[row][col] = newColor; 
        for(int i = 0;i<4;i++) {
            int nrow = row + delRow[i]; 
            int ncol = col + delCol[i]; 
            dfs(nrow, ncol,image, newColor, delRow, delCol, iniColor); 
            
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newc) {
        int oldc=image[sr][sc];
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        int n= image.size();
        int m= image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        dfs1(sr,sc,image,newc,delRow,delCol,oldc,vis);
        return image;
    }
    
    void dfs1(int row, int col,vector<vector<int>>& image, int newColor, int delRow[], int delCol[],
     int iniColor, vector<vector<int>>& vis){
        vis[row][col]=1;
        image[row][col]=newColor;
        
        for(int i=0;i<4;i++){
            int nrow= row+ delRow[i];
            int ncol= col+ delCol[i];
            
            if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size() && vis[nrow][ncol]!=1                    && image[nrow][ncol]== iniColor){
                dfs1(nrow, ncol, image, newColor, delRow, delCol, iniColor, vis);
            }
        }
    }
        
        
        
        
};