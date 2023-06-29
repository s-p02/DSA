class DisjointSet{
    public:
        vector<int> size,parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int findUpar(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]= findUpar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulpu= findUpar(u);
        int ulpv= findUpar(v);
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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int maxcol=0;
        for(auto it: stones){
            maxrow= max(maxrow, it[0]);
            maxcol= max(maxcol, it[1]);
        }
        DisjointSet ds(maxrow + maxcol +2);
        unordered_map<int, int> stoneNodes;
        for(auto it: stones){
            int row= it[0];
            int col= it[1]+ maxrow+1;
            ds.unionBySize(row,col);
            stoneNodes[row] = 1;
            stoneNodes[col] = 1;
        }
        
        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUpar(it.first) == it.first) {
                cnt++;
            }
        }
        return stones.size()-cnt;
    }
};