class DisjointSet{
    public:
        vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findUPar(int node){
        if(node== parent[node]){
            return node;
        }
        return parent[node]= findUPar(parent[node]);
    }
    
    void unionbysize(int u, int v){
        int ulp_u= findUPar(u);
        int ulp_v= findUPar(v);
        if(ulp_u== ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]= ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]= ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    
    bool isValid(int i, int j, int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        DisjointSet ds(n*n);
        
        int dr[]= {-1,0,1,0};
        int dc[]= {0,-1,0,1};
        
        // connect all the ones
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for (int ind=0;ind<4;ind++){
                    int nrow= i+dr[ind];
                    int ncol= j+dc[ind];
                    if(isValid(nrow, ncol, n) && grid[nrow][ncol]==1){
                        int node= i*n+j;
                        int adjnode= nrow*n +ncol;
                        ds.unionbysize(node,adjnode);
                    }
                }
            }
        }
        
        // Check for all the zeros
        int maxi= -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                set<int> st;
                for (int ind=0;ind<4;ind++){
                    int nrow= i+dr[ind];
                    int ncol= j+dc[ind];
                    if(isValid(nrow, ncol, n) && grid[nrow][ncol]==1){
                        st.insert(ds.findUPar(nrow*n +ncol));
                    }
                    int sizeTotal=1;
                    for(auto it:st){
                        sizeTotal= sizeTotal + ds.size[it];
                    }
                    maxi= max(maxi, sizeTotal);
                }
            }
        }
        
        // if cell has all ones and no zeros
        if(maxi==-1){
            return n*n;
        }
        else{
            return maxi;
        }
    }
};