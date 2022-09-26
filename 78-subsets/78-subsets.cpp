class Solution {
public:
    void recur(int i,vector<int>& nums,int n,vector<int>&ans,vector<vector<int>>&res){
        if(i==n){
            res.push_back(ans);
            return;
        }
        // pick
        ans.push_back(nums[i]);
        recur(i+1,nums,n,ans,res);
        
        //remove
        ans.pop_back();
        
        //not pick
        recur(i+1,nums,n,ans,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        int n= nums.size();
        recur(0,nums,n,ans,res);
        return res;    
    }
};