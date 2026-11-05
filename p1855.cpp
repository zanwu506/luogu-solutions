#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,t;
    cin>>n>>m>>t;
    vector<int> money(n);
    vector<int> time(n);
    for(int i=0;i<n;i++){
        cin>>money[i]>>time[i];
    }
    vector<vector<int>> dp(m+1,vector<int>(t+1,0));
     for(int i=0;i<n;i++){
        for(int j=m;j>=money[i];j--){
            for(int k=t;k>=time[i];k--){
                dp[j][k]=max(dp[j][k],dp[j-money[i]][k-time[i]]+1);
            }
        }
     }
     int ans=0;
     for(int i=0;i<=m;i++){
        for(int j=0;j<=t;j++){
            if(dp[i][j]>ans)ans=dp[i][j];
        }
     }
     cout<<ans<<endl;
     return 0;
}