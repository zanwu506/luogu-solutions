#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n,m;
    cin>>n>>m;
    vector<int>route(m+1,0);
    for(int i=1;i<=m;i++){
        cin>>route[i];
    }
    vector<int>a(n+1,0);
    vector<int>b(n+1,0);
    vector<int>c(n+1,0);
    for(int i=1;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    vector<int> diff(n+1,0);
    int pur=1;
    for(int i=1;i<m;i++){
        pur=route[i];
        int l=pur;
        int r=route[i+1];
        if(l>r)swap(r,l);
        diff[l]++;
        diff[r]--;
        pur=r;
    }
    vector<int>cnt(n+1,0);
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=diff[i];
        cnt[i]=sum;
    }
    int ans=0;
    for(int i=1;i<n;i++){
        ans+=min(a[i]*cnt[i],b[i]*cnt[i]+c[i]);
    }
    cout<<ans<<endl;
    return 0;
}