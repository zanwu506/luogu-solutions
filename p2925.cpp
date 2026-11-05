#include<bits/stdc++.h>
using namespace std;

int main(){
    int c,h;
    cin>>c>>h;
    vector<int>w(h);
    for(int i=0;i<h;i++){
        cin>>w[i];
    }
    vector<int>dp(c+1,0);
    for(int i=0;i<h;i++){
        for(int j=c;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
        }
    }
    cout<<dp[c]<<endl;
    return 0;
}