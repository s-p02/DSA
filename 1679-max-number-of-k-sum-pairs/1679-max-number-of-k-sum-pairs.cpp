class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int i=0;
        int j= nums.size()-1;
        sort(nums.begin(),nums.end());
        int cnt=0;
        while(j>i){
            if(nums[i]+nums[j]==k){
                i++;
                j--;
                cnt++;
            }
            else if(nums[i]+nums[j]<k){
                i++;
            }
            else{
                j--;
            }
        }
        return cnt;
        
    }
};