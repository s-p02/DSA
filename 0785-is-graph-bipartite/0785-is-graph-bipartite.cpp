class Solution {
public:
    bool bfs(int start, int n,vector<vector<int>>& graph, int color[]){
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            
            for(auto it: graph[node]){
                // if adjacent not colored
                if(color[it]==-1){
                    q.push(it);
                    color[it]=!color[node];
                }
                
                // if adjacent colored but same as node color then not bipartite
                
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int start,vector<vector<int>>& graph, int color[], int col){
        color[start]=col;
        for(auto it: graph[start]){
            // if not colored
            if(color[it]==-1){
                if(dfs(it,graph,color, !col)==false){
                    return false;
                }
            }
            // if colored and same as adjacent color not bipartite graph
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n= graph.size();
        int color[n];
        for(int i=0;i<n;i++){
            color[i]=-1;
        }
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                // if(bfs(i,n,graph,color)==false){
                //     return false;
                // }
                if(dfs(i,graph,color,0)==false){
                    return false;
                }
            }
        }
        return true;
        
    }
};