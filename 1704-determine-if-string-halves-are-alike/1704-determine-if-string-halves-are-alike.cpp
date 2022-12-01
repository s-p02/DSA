class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||
           ch=='E'||ch=='I'||ch=='O'||ch=='U'){
            return true;
        }
        else{
            return false;
        }
    }
    bool halvesAreAlike(string s) {
        int n= s.size();
        int cnt1=0,cnt2=0;
        for(int i=0;i<n/2;i++){
            if(isvowel(s[i])){
                cnt1++;
            }
        }
        for(int i=n/2;i<n;i++){
            if(isvowel(s[i])){
                cnt2++;
            }
        }
        
        if(cnt1==cnt2){
            return true;
        }
        
        return false;
        
    }
};