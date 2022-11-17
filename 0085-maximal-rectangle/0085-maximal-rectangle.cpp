class Solution {
public:
    int histogramArea(vector<int> histo){
        int n= histo.size();
        stack <int> st;
        int maxi= INT_MIN;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || histo[st.top()]>= histo[i])){
                int height= histo[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width= i;
                }
                else{
                    width= i-st.top()-1;
                }
                maxi= max(maxi, height*width);
            }
            st.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<int> temp(m,0);
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') {
                    temp[j]++;
                } 
                else{
                    temp[j]=0;
                }
            }
            int area= histogramArea(temp);
            maxArea= max(maxArea,area);
        }
        return maxArea;
    }
};