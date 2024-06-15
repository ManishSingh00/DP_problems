// here we are taking an extra hash array to store the idx of a element which can be taken for the current element before it. 
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        vector<int>dp(nums.size()+5,1);
        vector<int>hash(n);
        int max_idx = 0;
        for(int i = 0; i< n; i++) hash[i] = i;
        int max_length = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] &&  dp[i] < 1+dp[j]){
                    dp[i] = 1+ dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > max_length){
                max_length = dp[i];
                max_idx = i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[max_idx]);
        while(hash[max_idx] != max_idx){
            max_idx = hash[max_idx];
            ans.push_back(nums[max_idx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
