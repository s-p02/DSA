class Solution {
public:
    int addMinimum(string word) {
        stack<char> st;
        for(int i=0;i<word.size();i++){
            st.push(word[i]);
        }
        int cnt=0;
        while(!st.empty()){
            if(!st.empty() && st.top()=='c'){
                st.pop();
            }
            else{
                cnt++;
            }
            if(!st.empty() && st.top()=='b'){
                st.pop();
            }
            else{
                cnt++;
            }
             if(!st.empty() && st.top()=='a'){
                st.pop();
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
    
};