 class Solution 
{
public:
    vector<vector<string>> res;
    bool ispalindrome(string &s) 
    {
        int l=0, h=s.size()-1;
        while(l<h)
        {
            if(s[l]!=s[h]) return false;
            l++;
            h--;
        }
        return true;
    }

    void find(int i, string &s, string temp, vector<string> valid)
    {
        if(i==s.size())
        {
            if(temp.empty())
                res.push_back(valid);
            return;
        } 

        temp += s[i];
        find(i+1, s, temp, valid);
        if(ispalindrome(temp))
        {
            valid.push_back(temp);
            find(i+1, s, "", valid);
        }
        
    }

    vector<vector<string>> partition(string s) 
    {
        vector<string> valid;
        find(0, s, "", valid);
        return res;   
    }
};