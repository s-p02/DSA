// Method with DSU
class DisjointSet {
    public:
        vector<int> rank, parent, size;
        DisjointSet(int n) {
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }
        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n= mat.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cnt++;
        }
        return cnt;
    }
};







//Method with DFS



//class Solution {
// public:
//     void dfs(int node,vector<int> adjLs[],int vis[]){
//         vis[node]=1;
//         for(auto it: adjLs[node]){
//             if(!vis[it]){
//                 dfs(it,adjLs,vis);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& adj) {
//         int V= adj.size();
//         vector<int> adjLs[V];
        
//         // convert Matrix to List
//         for(int i=0;i<V;i++){
//             for(int j=0;j<V;j++){
//                 if(adj[i][j]==1 && i!=j){
//                     adjLs[i].push_back(j);
//                     adjLs[j].push_back(i);
//                 }
//             }
//         }
        
        
//         int vis[V];
//         for(int i=0;i<V;i++){
//             vis[i]=0;
//         }
//         int cnt=0;
//         for(int i=0;i<V;i++){
//             if(!vis[i]){
//                 cnt++;
//                 dfs(i,adjLs,vis);
//             }
//         }
        
//         return cnt;
        
//     }
// };

