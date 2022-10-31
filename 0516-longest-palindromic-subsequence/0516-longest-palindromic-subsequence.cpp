class Solution {
public:
    int lcs(string &s , string &t){
        int n= s.size();
        int m= t.size();
        vector<int> prev(m+1,0);
        for(int i=0;i<=m;i++){ // base case where if ind1==0 then ind2 can range from 0 to m
            prev[i]=0;
        }
        
        // table
        
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1,0);
            curr[0]=0;  // base case where if ind2==0 then ind1 can range from 0 to n
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]= 1+ prev[j-1];
                }
                else{
                    curr[j]= max(prev[j],curr[j-1]);
                }
            }
            prev= curr;
        }
        return prev[m]; 
    }
    int longestPalindromeSubseq(string s) {
        string t= s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
};