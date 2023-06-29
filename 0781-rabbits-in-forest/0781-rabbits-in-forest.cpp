// Single Pass solution with same logic
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.empty()) return 0;
        unordered_map<int,int> mpp;
        int cnt=0;
        for(int it:answers){
            if(it==0) cnt++;
            else{
                if(mpp[it]==0) cnt+=(it+1);
                mpp[it]++;
                if(mpp[it]==it+1){
                    mpp[it]=0;
                }
            }
        }
        return cnt;
    }
};



// Double Pass But same can be converted to single pass solution with same logic just slight modification
 
// class Solution {
// public:
//     int numRabbits(vector<int>& answers) {
//         if(answers.empty()) return 0;
//         unordered_map<int,int> mpp;
//         int cnt=0;
        
//         for(int it:answers){
//             if(it==0) cnt++;
//             else{
//                 mpp[it]++;
//                 if(mpp[it]==it+1){
//                     cnt+=(it+1);
//                     mpp[it]=0;
//                 }
//             }
//         }
//         for(auto it: mpp){
//             if(it.second!=0){
//                 cnt+= (it.first+1);
//             }
//         }
//         return cnt;
//     }
// };