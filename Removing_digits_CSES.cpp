#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int>dp;

    vector<int>get_digit(int n){
        vector<int>res;
        while(n>0){
           if(n%10!=0) res.push_back(n%10);
            n=n/10;
        }
        return res;
    }
int f(int n){
    if(n==0) return 0;
    if(n<=9) return 1;
    if(dp[n]!=-1) return dp[n];
    vector<int>digits=get_digit(n);
    int ans=INT_MAX;
    for(int i=0;i<digits.size();i++){
        ans=min(ans,f(n-digits[i]));
    }
    return dp[n]=1+ans;

}

// int fbu(int n){
//     dp[0]=0;
//     for(int i=1;i<=9;i++) dp[i]=1;
//     for(int k=10;k<=n;k++){
//         vector<int>d=get_digit(k);
//         int ans=INT_MAX;
//         for(int j=0;j<d.size();j++){
//             ans=min(ans,dp[k-d[j]]);
//         }
//         dp[k]=1+ans;
//     }
//     return dp[n];
// }
int main(){
    int n;
    cin>>n;
    dp.resize(1000005,-1);
    cout<<f(n);
    return 0;
}
