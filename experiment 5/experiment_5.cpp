class Solution {
public:

    int how_many(vector<int> &v,int sum,int i,int target, vector<vector<int>> &dp){

        if(i == v.size()){
            return sum == target;
        }

        if(sum > target) return 0;

        if(dp[i][sum] != -1) return dp[i][sum];

        int not_take = how_many(v,sum,i+1,target,dp);

        int take = how_many(v,sum + v[i],i+1,target,dp);

        return dp[i][sum] = take + not_take;
    }

    int perfectSum(vector<int>& v, int target) {

        int n = v.size();

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return how_many(v,0,0,target,dp);
    }
};