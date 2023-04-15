class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                if(it!=-1){
                    indegree[it]++;
                }
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        int cnt=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){
                if(it!=-1){
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push(it);
                    }
                }
            }
        }
        
        vector<bool> visited(n);
        int result = -1;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0 || visited[i]) continue;
            
            visited[i] = true;
            
            int cur = adj[i][0];
            int cycleLength = 1;
            while (cur != i) {
                visited[cur] = true;
                cur = adj[cur][0];
                ++cycleLength;
            }
            result = max(result, cycleLength);
        }
        return result;
        
    }
};