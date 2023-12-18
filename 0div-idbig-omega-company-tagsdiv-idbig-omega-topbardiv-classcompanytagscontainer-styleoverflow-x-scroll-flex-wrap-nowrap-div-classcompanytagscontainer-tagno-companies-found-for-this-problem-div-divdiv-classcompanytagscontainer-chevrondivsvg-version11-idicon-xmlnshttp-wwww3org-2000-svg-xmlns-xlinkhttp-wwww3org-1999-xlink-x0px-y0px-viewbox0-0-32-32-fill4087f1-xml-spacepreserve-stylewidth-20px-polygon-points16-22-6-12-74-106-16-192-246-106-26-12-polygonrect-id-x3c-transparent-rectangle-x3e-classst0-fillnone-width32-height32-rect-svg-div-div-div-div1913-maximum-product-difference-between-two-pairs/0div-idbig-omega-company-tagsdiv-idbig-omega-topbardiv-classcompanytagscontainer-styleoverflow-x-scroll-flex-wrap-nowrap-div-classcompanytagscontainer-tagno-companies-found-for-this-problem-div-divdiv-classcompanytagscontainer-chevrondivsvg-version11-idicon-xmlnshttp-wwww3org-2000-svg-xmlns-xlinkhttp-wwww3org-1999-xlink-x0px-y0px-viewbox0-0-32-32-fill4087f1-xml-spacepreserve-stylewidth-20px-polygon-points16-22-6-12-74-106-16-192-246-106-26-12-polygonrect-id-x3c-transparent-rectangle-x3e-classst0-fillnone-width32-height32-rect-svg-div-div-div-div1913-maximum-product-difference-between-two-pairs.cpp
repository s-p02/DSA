class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int a= nums[n-1];
        int b= nums[n-2];
        int c= nums[0];
        int d= nums[1];
        return (a*b)-(c*d);
        
    }
};