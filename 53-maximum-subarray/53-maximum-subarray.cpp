// marked only if we want to return the subarray along with max sum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		//vector<int> subarray;
        int max=nums[0];
		int sum=0;
		//int s=0;
		for (int i=0;i<nums.size();i++){
			sum=sum+nums[i];
			if (sum>max){
				max=sum;
				// subarray.clear();
				// subarray.push_back(s);// start index
				// subarray.push_back(i);// end index
			}
			if(sum<0){
				sum=0;
				//s=i+1;
			}
		}
		// for(int i=subarray[0];i<=subarray[1];i++){
		// 	cout<<nums[i]<<" ";
		// }
		// cout<<endl;
		return max;
    }
	
};