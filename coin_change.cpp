class Solution {
public:
    vector<int>dp;
    int f(vector<int>& coins,int sum){
        if(sum==0) return 0;
        if(dp[sum]!=-1) return dp[sum];
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(sum-coins[i]<0) continue;
            ans=min(ans,f(coins,sum-coins[i]));
        }
        if(ans==INT_MAX) return dp[sum]=INT_MAX;
        return dp[sum]=1+ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(10005,-1);
        int res= f(coins,amount);
        if(res==INT_MAX) return -1;
        else return res;
    }
};
