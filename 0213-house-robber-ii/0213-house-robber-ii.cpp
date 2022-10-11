class Solution {
public:
    long long solve(vector<int>& arr){
        int n= arr.size();
        long long prev=arr[0];
        long long prev2=0;
        for(int i=1;i<n;i++){
            long long pick= arr[i];
            if(i>1){
                pick+=prev2;
            }
            long long notpick= 0+ prev;
            long long curr= max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> arr1,arr2;
        for(int i=0;i<n;i++){
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }
        long long ans1= solve(arr1);
        long long ans2= solve(arr2);
        
        return max(ans1,ans2);
    }
};