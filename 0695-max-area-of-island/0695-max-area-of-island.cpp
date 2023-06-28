// This can be done using DFS(RECURSION) BUT DSU PROVIDES BETTER TC

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
        if(parent[node]==node){
            return node;
        }
        return parent[node]= findUPar(parent[node]);
    }
    
    void unionbysize(int u, int v){
        int ulpu= findUPar(u);
        int ulpv= findUPar(v);
        if(ulpu==ulpv) return;
        if(size[ulpu]<size[ulpv]){
            parent[ulpu]=ulpv;
            size[ulpv]+=size[ulpu];
        }
        else{
            parent[ulpv]=ulpu;
            size[ulpu]+=size[ulpv];
        }
    }
    
};
class Solution {
public:
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        DisjointSet ds(n*m-1);
        bool b= false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                b= true;
                for(int k=0;k<4;k++){
                    int nrow= i+dr[k];
                    int ncol= j+dc[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                        if(grid[nrow][ncol]==1){
                            int node= i*m+j;
                            int adjnode= nrow *m+ ncol;
                            ds.unionbysize(node, adjnode);
                        }
                    }
                }
            }
        }
        if(b==false){
            return 0;
        }
        int maxi= INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxi= max(maxi, ds.size[i*m+j]);
                }
            }
        }
        return maxi;
    }
};