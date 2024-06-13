#include<iostream>
#include<vector>
#include<climits>
using namespace std;

    vector<int>dp;

    int count;
    int f(int n){
        if(n==0) return 1;
        if (dp[n]!=-1) return dp[n];
        int count=0;
        for(int i=1;i<=6;i++){
            if((n-i)<0) break;
           count=count+f(n-i);
        }
        return dp[n]=count;
    }

    int fbu(int n){
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int count=0;
            for(int j=1;j<=6;j++){
                if(i-j<0) break;
                count=count+dp[i-j];
            }
            dp[i]=count;
        }
        return dp[n];
    }
int main(){
    int n;
    cin>>n;
    
        dp.resize(10005,-1);
        cout<<fbu(n);
    
    return 0;
}
