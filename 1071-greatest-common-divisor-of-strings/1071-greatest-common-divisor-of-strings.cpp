class Solution {
public:
    bool divideString(string &s,string &t){
        
        int n=s.size(),m=t.size();
        //if the length of t doesnt divide length of s then return false
        if(n%m){
            return false;
        }
        int val=(n/m);
        int i=0;
        bool flag=true;
        //we will run a while loop to traverse till the length of s and check if matches with
        // t[j] with s[i+j]
        while(i<n&&val){
            
            for(int j=0;j<m;j++){
                if(s[i+j]!=t[j]){
                    //if not then we will make our flag false
                    flag=false;
                }
            }
            i+=m;
            val--;
        }
        //returning the flag value
        return flag;
    }
    string gcdOfStrings(string str1, string str2) {
        string ans="",t="";
        //The max length of the ans can be gcd of the both string length
        //as the length of ans must divide the length of str1 and str2
        int gcd=__gcd(str1.size(),str2.size());
        //we will run a for loop till gcd and if at any index the str1[i]!=str2[i]
        //then we will break 
        //else we will call the divideString function to check if the cur substring divides
        //both str1 and str2
        for(int i=0;i<=gcd;i++){
            if(str1[i]!=str2[i]){
                break;
            }
            t+=str1[i];
            
            if(divideString(str1,t)&&divideString(str2,t)){
                ans=t;//if it divides then we will store it in ans
            }
        }
        //return the ans
        return ans;
    }
};