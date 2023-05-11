// using bfs
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> adjrev[n];
        int indegree[n];
        // initialize indegree to 0
        for(int i=0;i<n;i++){
            indegree[i]=0;
        }
        
        // reverse the adjlist and calculate the new indegree array
        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safenodes;
        
        while(!q.empty()){
            int node= q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it: adjrev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safenodes.begin(), safenodes.end());
        return safenodes;
        
    }
};



// using dfs 
//class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n= graph.size();
//         int vis[n],pathvis[n], check[n];
//         for(int i=0;i<n;i++){
//             vis[i]=0;
//             pathvis[i]=0;
//             check[i]=0;
//         }
        
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 dfs(i, graph, vis, pathvis, check);
//             }
//         }
        
//         vector<int> res;
//         for(int i=0;i<n;i++){
//             if(check[i]==1){
//                 res.push_back(i);
//             }
//         }
//         return res;
//     }
    
//     bool dfs(int node,vector<vector<int>>& graph,int vis[],int pathvis[],int check[] ){
//         vis[node]=1;
//         pathvis[node]=1;
//         check[node]=0;
        
//         for(auto it: graph[node]){
//             if(!vis[it]){
//                 if(dfs(it, graph, vis, pathvis, check)==true){
//                    return true; 
//                 }
//             }
//             else if(pathvis[it]==1){
//                 return true;
//             }
            
//         }
        
//         // After all dfs calls have been completed and there is no cycle then we can mark the node as safe node
        
//         check[node]=1;
//         pathvis[node]=0;
//         return false;
//     }
// };