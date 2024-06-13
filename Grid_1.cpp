#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int dp[1005][1005];

int f(vector<vector<char>>& arr,int i, int j,int h,int w){
    if(i >=h || i < 0 || j >= w || j < 0 || arr[i][j] == '#') return 0;
    if(i == h-1 && j == w-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    ans = (f(arr,i+1,j,h,w)%mod + f(arr,i,j+1,h,w)%mod)%mod;
    return dp[i][j] = ans;
}
int main(){
    int h,w;
    cin>>h>>w;
    memset(dp,-1,sizeof dp);
    vector<vector<char>>arr(h,vector<char>(w,'*'));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char x;
            cin>>x;
            arr[i][j] = x;
        }
    }
    cout<<f(arr,0,0,h,w);
    return 0;
}
