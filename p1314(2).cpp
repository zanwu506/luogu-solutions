#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s;
vector<int> w,v,l,r,cnt,sum;
int L=0,R=0;
int ans=LONG_LONG_MAX;

int check(int x){
    cnt.assign(n+1,0);
    sum.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cnt[i]=cnt[i-1]+(w[i]>x?1:0);
        sum[i]=sum[i-1]+(w[i]>x?v[i]:0);
    }
    int y=0;
    for(int i=1;i<=m;i++){
        int c=cnt[r[i]]-cnt[l[i]-1];
        int v=sum[r[i]]-sum[l[i]-1];
        y+=c*v;
    }
    return y;
}
signed main(){
    cin>>n>>m>>s;
    w.assign(n+1,0);
    v.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
        R=max(R,w[i]);
    }
    R++;
    l.assign(m+1,0);
    r.assign(m+1,0);
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
    }
    while(L<=R){
        int mid=L+(R-L)/2;
        int y=check(mid);
        if(y>s){
            L=mid+1;
        }else if(y<s){
            R=mid-1;
        }else if(y==s){
            ans=0;
            break;
        }
        ans=min(ans,llabs(y-s));
    }
    cout<<ans<<endl;
    return 0;

}