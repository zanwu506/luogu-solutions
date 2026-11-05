#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,p,s;
    cin>>n>>p>>s;
    vector<int>w(n);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    int left=0;
    int right=s;
    vector<int>dp(s+1,0);
    for(int i=0;i<n;i++){
            for(int j=s;j>=w[i];j--){
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        if(dp[s]<p){
            cout<<"No Solution!"<<endl;
            return 0;
        }
    while(left<=right){
        int mid=(right-left)/2+left;
        vector<int>dp(s+1,0);
        for(int i=0;i<n;i++){
            if(w[i]>mid){
                continue;
            }
            for(int j=s;j>=w[i];j--){
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        if(dp[s]>=p){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    cout<<left<<endl;
    return 0;
}