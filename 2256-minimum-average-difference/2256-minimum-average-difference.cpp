class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix_sums(n);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                prefix_sums[i] = nums[i];
            } else {
                prefix_sums[i] = prefix_sums[i-1] + nums[i];
            }
        }

        int min_avg_diff = INT_MAX;
        int min_avg_diff_index = 0;
        for (int i = 0; i < n; i++) {
            double first_avg = floor(prefix_sums[i] / (i + 1));
            double last_avg = 0;
            if (i != n - 1) {
                last_avg = floor((prefix_sums[n-1] - prefix_sums[i]) / (n - i - 1));
            }
            int avg_diff = abs(first_avg - last_avg);
            if (avg_diff < min_avg_diff) {
                min_avg_diff = avg_diff;
                min_avg_diff_index = i;
            }
        }

        return min_avg_diff_index;
    }
};