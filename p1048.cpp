#include<bits/stdc++.h>
using namespace std;


int main(){
    int t,m;
    cin>>t>>m;
    vector<int>w(m);
    vector<int>v(m);
    for(int i=0;i<m;i++){
        cin>>w[i]>>v[i];
    }
    vector<int>dp(t+1,0);
    dp[0]=0;
    for(int i=0;i<m;i++){
        for(int j=t;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[t]<<endl;
    return 0;

}