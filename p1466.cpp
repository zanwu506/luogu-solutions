#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    if(sum%2!=0){
        cout<<0<<endl;
        return 0;
    }
    vector<int> dp(sum+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=sum/2;j>=i;j--){
        //     新的 dp[j] = 不选 i 的方案数 + 选 i 的方案数
        //    = dp[j] + dp[j - i]
            dp[j]+=dp[j-i];
        }
    }
    cout<<dp[sum/2]/2<<endl;
    return 0;
}