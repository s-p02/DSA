class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        
        vector<int> vis(n+1,0);
        int ball=1;
        vis[ball]=1;
        int step=1;
        while(true){
            if((ball+(step*k))%n==0){
                ball=n;
            }
            else{
                ball= (ball + (step*k))%n;
            }
            vis[ball]++;
            if(vis[ball]==2){
                break;
            }
            step++;
        }
        vector<int> res;
        for(int i=1;i<vis.size();i++){
            if(vis[i]==0){
                res.push_back(i);
            }
        }
        return res;
    }
};