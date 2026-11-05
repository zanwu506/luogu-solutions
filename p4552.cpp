#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> diff(n+2,0);
    for(int i=1;i<=n;i++){
        diff[i]=a[i]-a[i-1];
    }
    int sumZ=0,sumF=0;
    for(int i=2;i<=n;i++){
        if(diff[i]>0){
            sumZ+=diff[i];
        }else if(diff[i]<0){
            sumF+=-diff[i];
        }
    }
    int cnt1=max(sumZ,sumF);
    int cnt2=0;
    if(sumZ>sumF){
        cnt2=sumZ-sumF+1;
    }else cnt2=sumF-sumZ+1;
    cout<<cnt1<<"\n"<<cnt2<<endl;
    return 0;
}