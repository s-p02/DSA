class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int> hset;
        for(int i: nums){
            hset.insert(i);
        }
        int ans= INT_MIN;
        
        for(int num: hset){
            if(hset.count(num-1)==0){
                int first_ele= num;
                int current_length=1;
                
                while(hset.count(first_ele+1)==true){
                    first_ele++;
                    current_length++;
                }
                
                ans= max(ans,current_length);           
            }
        }
        return ans;  
    }
};