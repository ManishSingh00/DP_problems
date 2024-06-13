#include<bits/stdc++.h>
using namespace std;
 int dp[100005];
 int f(vector<list<int>>&graph,int src){
   if(dp[src]!=-1) return dp[src];
   bool leaf=1;
   int maxvalue=0;
   for(int neighbour : graph[src]){
     leaf=0;
     maxvalue=max(maxvalue,f(graph,neighbour));
   }
    return dp[src]=leaf?0:1+maxvalue;
 }
int main(){
  int n;
  int m;
  cin>>n>>m;
  memset(dp,-1,sizeof dp);
  vector<list<int>>graph(n+1);
  while(m--){
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
  }
  int res=INT_MIN;
  for(int i=1;i<=n;i++){
    res=max(res,f(graph,i));
  }
  cout<<res;
  return 0;
}
