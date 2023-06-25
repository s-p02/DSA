class DisjointSet{
    public:
    vector<int> size, parents;
    DisjointSet( int n){
        size.resize(n+1,1);
        parents.resize(n+1);
        for(int i=0;i<n;i++){
            parents[i]=i;
        }
    }
    int findUPar(int node){
        if(parents[node]==node){
            return node;
        }
        return parents[node]=findUPar(parents[node]);
    }
    
    void unionbysize(int u, int v){
        int ulpu= findUPar(u);
        int ulpv= findUPar(v);
        if(ulpv== ulpu){
            return;
        }
        if(size[ulpu]<size[ulpv]){
            parents[ulpu]=ulpv;
            size[ulpv]+=size[ulpu];
        }
        else{
            parents[ulpv]=ulpu;
            size[ulpu]+=size[ulpv];
        }
    } 
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string str= accounts[i][j];
                if(mpp.find(str)==mpp.end()){
                    mpp[str]=i;
                }
                else{
                    ds.unionbysize(mpp[str],i);
                }
            }
        }
        vector<vector<string>> mat(n);
        for(auto it: mpp){
            string str= it.first;
            int node= ds.findUPar(it.second);
            mat[node].push_back(str);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mat[i].size()==0){
                continue;
            }
            sort(mat[i].begin(),mat[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(int j=0;j<mat[i].size();j++){
                temp.push_back(mat[i][j]);
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};