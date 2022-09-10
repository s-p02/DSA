class Solution {
public:
    string greatestLetter(string s) {
        sort(s.begin(),s.end());
        int count=0;
        string ch;
        bool temp=false,temp1=false;
        for(int i=s.size()-1;i>=0;i--){
            ch=s[i];
            for(int j =s.size()-1;j>=0;j--){
                if (j==i)
                    continue;
                if(s[j]==ch[0]+32){
                    temp=true;
                    break;
                }    
                if(s[j]==ch[0]-32){
                    temp1=true;
                    break;
                }
            }
            if(temp){
                return ch;
            }
            if(temp1){
               ch=ch[0]-32;
                return ch;
            }
                
        }
        ch="";
        return ch;
        
    }
};