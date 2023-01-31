class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        int n = scores.size();
        for (int i=0; i<n; i++) {
            players.push_back({ages[i], scores[i]});
        }
        sort(players.begin(), players.end());
        
        std::vector<int> dp(scores.size());
        int ans = 0;
        for(int i = 0; i < scores.size(); i++)
        {
            int score = players[i].second;
            dp[i] = players[i].second;

            //Add all of the players up to i and make sure that none of the players
            //before them have a lower score, since they are sorted in ascending age
            for(int j = 0; j < i; j++)
            {
                if(players[j].second <= players[i].second)
                {
                    dp[i] = std::max(dp[i], dp[j] + score);
                }
            }

            ans = std::max(dp[i], ans);
        }

        return ans;
    }
};