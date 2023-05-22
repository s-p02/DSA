class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<pair<int,int>> vec;
        for(auto it:mpp){
            vec.push_back({it.first,it.second});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(vec[i].first);
        }
        return res;
    }
};