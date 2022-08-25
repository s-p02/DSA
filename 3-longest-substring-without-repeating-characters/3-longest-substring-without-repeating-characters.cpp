class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        unordered_map<char,int> mpp;
        int left=0;
        int right=0;
        int maxi= INT_MIN;
        while(right<s.length()){
            if(mpp.find(s[right])!=mpp.end()){
                left=max(mpp[s[right]]+1,left);
            }
            mpp[s[right]]=right;
            maxi=max(maxi, right-left+1);  
            right++;
        }
        return maxi;
    }
};