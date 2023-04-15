class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>a(26,0);
        vector<int>b(26,0);
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            b[t[i]-'a']++;
        }
        if(a==b){
            return true;
        }
        return false;
        
    }
};