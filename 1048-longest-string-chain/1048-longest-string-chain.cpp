class Solution {
public:
    // sort the original on basis of length of string uisng comparator fn
    bool static comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    
    // compare whether String 1 is 1 character more than String 2:
    bool compare(string &s1, string &s2){
        
        // we have sorted the words array therefore ahead string will always be of more `         length than previous string:
        if(s1.size()!= s2.size()+1) return false;
        
        int first=0;
        int second=0;
        while(first<s1.size()){
            if(second<s2.size() && s1[first]== s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        // if both reach at the end simultaneously then return true
        if(first== s1.size() && second==s2.size()) return true;
        else return false;
        
    }
    int longestStrChain(vector<string>& words) {
        int n= words.size();
        vector<int> dp(n,1);
        
        // sort the original on basis of length of string uisng comparator fn
        sort(words.begin(),words.end(),comp);
        
        // TABULATION ALGO 
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && 1+ dp[j]>dp[i]){
                    dp[i]= 1+dp[j];
                }
            }
        }
        
        // maximum of the DP table gives us the length of LSC
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};