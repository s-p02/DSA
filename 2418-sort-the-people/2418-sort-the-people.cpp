class Solution {
public:
    struct ans{
        string name;
        int height;
    };
    bool static comp(ans a ,ans b){
        return(a.height>b.height);
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n= names.size();
        struct ans people[n];
        for(int i=0;i<names.size();i++){
            people[i].name= names[i];
            people[i].height=heights[i];
        }
        sort(people,people+n,comp);
        for(int i=0;i<n;i++){
            names[i]=people[i].name;
        }
        return names;
    }
};