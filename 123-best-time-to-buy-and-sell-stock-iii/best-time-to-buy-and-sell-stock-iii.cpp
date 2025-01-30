class Solution {
public:
    int fun(int index, int flag, int cap, vector<int>& arr, vector<vector<vector<int>>>& dp){
        if(index == arr.size()) return 0;
        else if(cap == 0) return 0;
        if(dp[index][flag][cap] != -1) return dp[index][flag][cap];

        if(flag){
            return dp[index][flag][cap] = max((-arr[index] + fun(index+1, 0, cap, arr, dp)), 
            (fun(index+1, 1, cap, arr, dp)));
        }
        return dp[index][flag][cap] = max((arr[index] + fun(index+1, 1, cap-1, arr, dp)), 
        (fun(index+1, 0, cap, arr, dp)));
    }

    int maxProfit(vector<int>& prices) {
        ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>>dp(2, vector<int>(3, 0));
        vector<vector<int>>curr(2, vector<int>(3, 0));
        // return fun(0, 1, 2, prices, dp);
        // for(int i = 0;i <= 1;i++){
        //     for(int j = 0;j <= 2;j++){
        //         dp[n][i][j] = 0;
        //     }
        // }
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j <= 1;j++){
        //         dp[i][j][0] = 0;
        //     }
        // }

        for(int i = n-1;i >= 0;i--){
            for(int j = 0;j <= 1;j++){
                for(int k = 1;k <= 2;k++){
                    if(j){
                        curr[j][k] = max((-prices[i] + dp[0][k]), 
                        (dp[1][k]));
                    }
                    else{
                        curr[j][k] = max((prices[i] + dp[1][k-1]), 
                        (dp[0][k]));
                    }
                }
            }
            dp = curr;
        }

        return dp[1][2];
    }
};