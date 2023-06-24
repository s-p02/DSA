class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n=s.size();
        int start=0;
        st.push(s[0]);
        vector<pair<int,int>> arr;
        for(int i=1;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                st.pop();
                if(st.empty()){
                    arr.push_back({start,i});
                    start=i+1;
                }
            }
        }
        string str="";
        for(auto it: arr){
            int start= it.first +1;
            int end= it.second;
            int len= end-start;
            string subs=s.substr(start, len);
            str+=subs;
        }
        return str;
    }
};