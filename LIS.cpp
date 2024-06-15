// Method 1 :- TOP_DOWN:-
class Solution {
public:
    vector<int>dp;
    int f(vector<int>& nums,int i){
        if(i==0) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN;
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]) ans=max(ans,f(nums,j));
        }
        if(ans==INT_MIN) return dp[i]=1;
        return dp[i]=1+ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(2505,-1);
        int finans=0;
        for(int i=0;i<nums.size();i++){
            finans=max(finans,f(nums,i));
        }
        return finans;
    }
};
// Method 1 :- Bottom_up:-
class Solution {
public:
    int fbu(vector<int>& nums){
        vector<int>dp(nums.size()+5,1);
        int max_length = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], 1+ dp[j]);
                }
            }
            max_length = max(max_length,dp[i]);
        }
        return max_length;
    }
    int lengthOfLIS(vector<int>& nums) {
        return fbu(nums);
    }
};




// Method  2 :- Topdown
class Solution {
public:
    int getAns(vector<int>& arr, int n, int ind, int prev_index, vector<vector<int>>& dp) {
    if (ind == n)
        return 0;
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];
    int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);
    int take = 0;
    if (prev_index == -1 || arr[ind] > arr[prev_index]) {
        take = 1 + getAns(arr, n, ind + 1, ind, dp);
    }
    return dp[ind][prev_index + 1] = max(notTake, take);
}
    int getAns_bu(vector<int>& arr, int n, vector<vector<int>>& dp){
        for(int ind=n-1;ind>=0;ind--){
            for(int prev_idx=ind-1;prev_idx>=-1;prev_idx--){
                int notTake = 0 + dp[ind+1][prev_idx+1];
                int take = 0;
                if(prev_idx == -1 || arr[ind] > arr[prev_idx]){
                    take = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev_idx+1] = max(notTake,take);
            
            }
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        return getAns_bu(nums, n, dp);
    }
};

// Method 2 :- Bottom_up :-
#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            int notTake = 0 + dp[ind+1][prev_index +1];
            int take = 0;
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                take = 1 + dp[ind+1][ind+1];
            }
            dp[ind][prev_index+1] = max(notTake,take);
        }
    }
    return dp[0][0];
}
int main() {	
	int arr[] = {10,9,2,5,3,7,101,18};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"The length of the longest increasing subsequence is "
        <<longestIncreasingSubsequence(arr,n);
	return 0;
}
