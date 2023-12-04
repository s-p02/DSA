class Solution {
public:
    string largestGoodInteger(string num) {
        int maxi=INT_MIN;
        string res="";
        for(int i=0;i<num.size()-2;i++){
            char ch= num[i];
            bool flag=true;
            for(int j=0;j<=2 && i+j<num.size();j++){
                char c= num[i+j];
                if(c!=ch){
                    flag=false;
                }
            }
            if(flag==true){
                int chc= ch-'0';
                if(chc>maxi){
                    maxi=chc;
                    res="";
                    for(int j=0;j<=2;j++){
                        res+=ch;
                    }
                }
            }
        }
        return res;
    }
};