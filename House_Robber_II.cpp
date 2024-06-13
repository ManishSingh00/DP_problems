class Solution {
public:
    vector<int> dp;
    int ftd(vector<int> nums,int i){
        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2) return max(nums[i],nums[i+1]);
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max((nums[i]+ftd(nums,i+2)),ftd(nums,i+1));
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(nums.size()+5,-1);
        vector<int>temp1,temp2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n-1;i++){
            temp1.push_back(nums[i]);
        }
        for(int i=1;i<n;i++){
            temp2.push_back(nums[i]);
        }
        int ans1=ftd(temp1,0);
        dp.clear();
        dp.resize(nums.size()+5,-1);

        int ans2=ftd(temp2,0);
        return max(ans1,ans2);
    
    }
};
