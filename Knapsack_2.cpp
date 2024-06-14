#include<iostream>
#include<vector>
#include<climits>
#include<string.h>
#define ll long long int
using namespace std;
    ll dp[105][100005];
    // vector<vector<ll> > dp(105,vector<ll>(100005,-1));
    ll f(vector<int>&wts,vector<int>&val,int idx,int tv){
        if(tv == 0) return 0;
        if(idx==wts.size()) return INT_MAX;
        if(dp[idx][tv]!=-1) return dp[idx][tv];
        ll ans=INT_MIN;

        ans=f(wts,val,idx+1,tv);
        if(val[idx]<=tv){
            ans=min(ans,wts[idx]+f(wts,val,idx+1,tv - val[idx]));
        }

        return dp[idx][tv]=ans;
    }
int main(){
    memset(dp,-1,sizeof dp);
    int n,w;
    cin>>n>>w;
    vector<int>wts;
    vector<int>val;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        wts.push_back(x);
        val.push_back(y);
    }
    int ans = -1;
    for(int i = 0; i<=n*1000;i++){
        if(f(wts,val,0,i) <= w){
            ans = i;
        }
    }
    cout<<ans;
    return 0;
}
