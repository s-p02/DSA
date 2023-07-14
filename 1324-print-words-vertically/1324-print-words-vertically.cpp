class Solution {
public:
    vector<string> printVertically(string s) {
        s+=" ";
        vector<string>st;
        string str="";
        int maxi=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                str+=s[i];
            }
            else{
                int len= str.size();
                st.push_back(str);
                str="";
                maxi=max(maxi, len);
            }
        }
        int i=0;
        vector<string> ans;
        while(i<maxi){
            string temp="";
            int lastNonSpace=0;
            for(auto it: st){
                if(i<it.size()){
                    temp+=it[i];
                    lastNonSpace=temp.size();
                }
                else{
                    temp+=' ';
                }
            }
            temp.resize(lastNonSpace);
            ans.push_back(temp);
            i++;
        }
        return ans;
    }
};