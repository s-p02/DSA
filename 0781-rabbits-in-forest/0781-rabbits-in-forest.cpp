class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.empty()) return 0;
        unordered_map<int,int> mpp;
        int cnt=0;
        
        for(int it:answers){
            if(it==0) cnt++;
            else{
                mpp[it]++;
                if(mpp[it]==it+1){
                    cnt+=(it+1);
                    mpp[it]=0;
                }
            }
        }
        for(auto it: mpp){
            if(it.second!=0){
                cnt+= (it.first+1);
            }
        }
        return cnt;
    }
};