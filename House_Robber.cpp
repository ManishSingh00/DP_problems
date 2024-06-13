class Solution {
public:
    vector<int> dp;
    int ftd(vector<int> nums,int i){
        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2) return max(nums[i],nums[i+1]);
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max((nums[i]+ftd(nums,i+2)),ftd(nums,i+1));
       
    }

    int fbu(vector<int>nums){
        if(nums.size()==1) return nums[0];
        dp[nums.size()-1]=nums[nums.size()-1];
        dp[nums.size()-2]=max(nums[nums.size()-1],nums[nums.size()-2]);
        for(int i =nums.size()-3;i>=0;i--){
            dp[i]=max(dp[i+2]+nums[i],dp[i+1]);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(nums.size(),-1);
        return fbu(nums);
    }
};
