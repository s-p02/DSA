class Solution {
public:
    void dfs(int sr, int sc,vector<vector<int>>&vis,vector<vector<int>>& image,int newc, int oldc){
        
        if(sr<0||sr>=image.size()|| sc<0||sc>=image[0].size()||image[sr][sc]!=oldc|| vis[sr][sc]==newc){
            return;
        }
        vis[sr][sc]=newc;
        dfs(sr+1,sc,vis,image,newc,oldc);
        dfs(sr-1,sc,vis,image,newc,oldc);
        dfs(sr,sc+1,vis,image,newc,oldc);
        dfs(sr,sc-1,vis,image,newc,oldc);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newc) {
        vector<vector<int>>vis;
        vis=image;
        int oldc=image[sr][sc];
        dfs(sr,sc,vis,image,newc,oldc);
        return vis;
    }
};