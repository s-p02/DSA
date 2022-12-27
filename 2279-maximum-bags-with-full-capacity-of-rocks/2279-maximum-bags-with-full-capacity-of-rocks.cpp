class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        vector<int> req(n);
        for(int i=0; i<n; i++)
        {
            req[i] = capacity[i] - rocks[i];
        }

        sort(req.begin(), req.end());
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            additionalRocks -= req[i];
            ans++;
            if(additionalRocks <= 0)
            {
                if(additionalRocks < 0) ans--;
                break;
            }
        }

        return ans;
    }
    
};