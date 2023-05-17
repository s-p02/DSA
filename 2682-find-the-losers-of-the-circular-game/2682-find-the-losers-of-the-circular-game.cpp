class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        
        vector<int> vis(n+1,0);
        int ball=1;
        bool flag=true;
        vis[ball]=1;
        int step=1;
        while(flag){
            if((ball+(step*k))%n==0){
                ball=n;
            }
            else{
                ball= (ball + (step*k))%n;
            }
            vis[ball]++;
            if(vis[ball]==2){
                flag=false;
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
//        sort(res.begin(),res.end());
        return res;
    }
};