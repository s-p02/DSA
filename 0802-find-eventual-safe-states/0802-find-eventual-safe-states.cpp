class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        int vis[n],pathvis[n], check[n];
        for(int i=0;i<n;i++){
            vis[i]=0;
            pathvis[i]=0;
            check[i]=0;
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathvis, check);
            }
        }
        
        vector<int> res;
        for(int i=0;i<n;i++){
            if(check[i]==1){
                res.push_back(i);
            }
        }
        return res;
    }
    
    bool dfs(int node,vector<vector<int>>& graph,int vis[],int pathvis[],int check[] ){
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        
        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(it, graph, vis, pathvis, check)==true){
                   return true; 
                }
            }
            else if(pathvis[it]==1){
                return true;
            }
            
        }
        
        // After all dfs calls have been completed and there is no cycle then we can mark the node as safe node
        
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
};