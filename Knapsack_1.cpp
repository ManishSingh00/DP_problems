#include<iostream>
#include<vector>
#include<climits>
#include<string.h>
#define ll long long int
using namespace std;
    ll dp[105][100005];
    // vector<vector<ll> > dp(105,vector<ll>(100005,-1));
    ll f(vector<int>&wts,vector<int>&val,int idx,int w){
        if(idx==wts.size()) return 0;
        if(dp[idx][w]!=-1) return dp[idx][w];
        ll ans=INT_MIN;

        ans=f(wts,val,idx+1,w);
        if(wts[idx]<=w){
            ans=max(ans,val[idx]+f(wts,val,idx+1,w-wts[idx]));
        }

        return dp[idx][w]=ans;
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
    cout<<f(wts,val,0,w);
    return 0;
}
