class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int target=0,sum;
        if(nums.empty()){
            return ans;
        }
        sort(nums.begin(),nums.end());
        int n= nums.size();
        for(int i=0;i<n;i++){
            long long rem= (long long)target- nums[i];
            int front=i+1;
            int back=n-1;
            while(front<back){
                sum= nums[front]+nums[back];
                if(sum>rem){
                    back--;
                }
                else if(sum<rem){
                    front++;
                }
                else{
                    vector<int> trip(3,0);
                    trip[0]=nums[i];
                    trip[1]=nums[front];
                    trip[2]=nums[back];
                    ans.push_back(trip);
                    
                    while(front<back && nums[front]==trip[1]){
                        front++;
                    }
                    
                    while(front<back && nums[back]==trip[2]){
                        back--;
                    }
                }
            }
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};