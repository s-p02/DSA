class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.empty()){
            return ans;
        }
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long remainder= (long long)target-nums[i]-nums[j];
                int front=j+1,end=n-1;
                while(front<end){
                    int sumfe=nums[front]+nums[end];
                    if(sumfe<remainder){
                        front++;
                    }
                    else if(sumfe>remainder){
                        end--;
                    }
                    else{
                        vector<int> quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[front];
                        quad[3]=nums[end];
                        ans.push_back(quad);
                        
                        // Handling Duplicates for the 3rd element
                        while(front<end && nums[front]==quad[2]){
                            front++;
                        }
                        
                        // Handling Duplicates for the 4th element
                        
                        while(front<end && nums[end]==quad[3]){
                            end--;
                        }
                    }
                }
                // Handling Duplicates for the 2nd element
                while(j+1<n && nums[j]==nums[j+1]){
                    j++;
                }
                
            }
            // Handling Duplicates for the 1st element
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};
