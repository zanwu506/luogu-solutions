#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int MAXA=5000;

int main(){
    int n;
    cin>>n;
    vector<long long>cnt(MAXA+1,0);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        cnt[t]++;
    }
    long long ans=0;
    for(int x=1;x<=MAXA;x++){
        if(cnt[x]<2)continue;
        long long a=cnt[x]*(cnt[x]-1)/2%MOD;
        long long b=0;
        for(int i=1;i<=x/2;i++){
            int j=x-i;
            if(i==j){
                if(cnt[i]>=2){
                b=(b+cnt[i]*(cnt[i]-1)/2)%MOD;
                }
            }else {
                b=(b+cnt[i]*cnt[j])%MOD;
            }
        }
        ans=(ans+a*b)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}