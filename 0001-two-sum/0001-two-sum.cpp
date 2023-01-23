// Hashmap: Optimal Approach TC: O(N) SC:O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            //check if key(i.e target-x) is present in the map
            
            //  if present
            if(mp.find(target-nums[i])!=mp.end()){ 
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                return ans;
            }
            
        //if not found then insert element into the map with index as value of key
            
            mp[nums[i]]=i;
        }
        
        return ans;
    }
};




// // Two Pointer Approach T.C: NlogN S.C: N
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans, temp;
//         temp=nums;
//         sort(temp.begin(),temp.end());
//         int n1,n2;
//         int left=0, right=nums.size()-1;
//         while(left<right){
//             if(temp[left]+temp[right]==target){
//                 n1=temp[left];
//                 n2=temp[right];
//                 break;
//             }
//             else if(temp[left]+temp[right]>target){
//                 right--;
//             }
//             else{
//                 left++;
//             }
//         }
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==n1){
//                 ans.push_back(i);
//             }
//             else if(nums[i]==n2){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };