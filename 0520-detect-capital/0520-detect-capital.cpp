class Solution {
public:
    bool detectCapitalUse(string word) {
        int num_capitals = 0;
        for(char c : word) {
            if(isupper(c)) {
                num_capitals++;
            }
        }
        return num_capitals == 0 || (num_capitals == 1 && isupper(word.at(0))) || num_capitals == word.size();     
    }
};