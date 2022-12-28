class Solution {
public:
    int getindex(int ele, vector<int>& v){
        auto it = find(v.begin(), v.end(), ele);
        if(it!=v.end()){
            return it-v.begin();
        }
        else return -1;
    }
    
    int findNextGreater(int ind,vector<int>& v){
        int ans=-1;
        for(int i= ind+1; i<v.size();i++){
            if(v[i]>v[ind]){
                ans=v[i];
                break;
            }
        }
        return ans;
    }
        
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        //int m= nums2.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            int ele= nums1[i];
            int ind= getindex(ele,nums2);
            res[i]= findNextGreater(ind,nums2);
        }
        
        return res;
    }
};