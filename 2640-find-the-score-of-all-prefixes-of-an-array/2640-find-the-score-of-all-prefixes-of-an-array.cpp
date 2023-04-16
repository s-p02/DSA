class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n=nums.size();
        long long maxi=nums[0];
        vector<long long> pre(n,0);
        for(int i=0;i<n;i++){
            long long ele= nums[i];
            maxi=max(maxi,ele);
            long long cover= ele+ maxi;
            if(i==0){
                pre[i]=cover;
            }
            else{
                pre[i]=pre[i-1]+cover;
            }
        }
        return pre;
    }
};