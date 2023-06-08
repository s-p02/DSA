class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int ind1=0;
        int ind2=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ind1=i;
                continue;
            }
            if(nums[i]==n){
                ind2=i;
                continue;
            }
        }
        int steps=0;
        if(ind1<ind2){
            steps= (ind1-0)+ (n-1-ind2);
        }
        else{
            steps= (ind1-0)+(n-1-ind2)-1;
        }
        return steps;
    }
};