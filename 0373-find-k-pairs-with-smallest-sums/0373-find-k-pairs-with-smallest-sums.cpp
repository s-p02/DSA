class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue< pair<int,vector<int>>> pq;
        
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(pq.size()<k){
                    vector<int> temp;
                    temp.push_back(nums1[i]);
                    temp.push_back(nums2[j]);
                    pq.push({nums1[i]+nums2[j],temp});
                }
                else{
                    if(nums1[i]+nums2[j]<pq.top().first){
                        pq.pop();
                        vector<int> temp;
                        temp.push_back(nums1[i]);
                        temp.push_back(nums2[j]);
                        pq.push({nums1[i]+nums2[j],temp});
                    }
                    else{
                        break;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
       return ans;
    }
};