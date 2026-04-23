class Solution {
public:
    int minDifference(vector<int>& arr) {
        int S = 0;
        for (int num : arr) S += num;

        int target = S / 2;
        int n = arr.size();

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : arr) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        for (int s1 = target; s1 >= 0; s1--) {
            if (dp[s1]) {
                return S - 2 * s1;
            }
        }

        return 0; // edge case
    }
};