class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int lo=i+1;
            int hi= n-1;
            while(lo<hi){
                if(nums[i]+nums[hi]+nums[lo]==0){
                    vector<int> temp(3,0);
                    temp[0]= nums[i];
                    temp[1]=nums[lo];
                    temp[2]=nums[hi];
                    ans.push_back(temp);
                    while(lo<hi && nums[lo]==temp[1]){
                        lo++;
                    }
                    while(lo<hi && nums[hi]==temp[2]){
                        hi--;
                    }
                }
                else if(nums[hi]+nums[lo]<-nums[i]){
                    lo++;
                }
                else{
                    hi--;
                }
            }
            while(i<n-1 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};