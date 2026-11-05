#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s;
vector<int> w;
vector<int> v;
vector<int>l;
vector<int>r;
vector<long long>cnt;
vector<long long>sum;
long long ans=LONG_LONG_MAX;
long long check(int x){
    long long y=0;
    for(int i=1;i<=n;i++){
            if(w[i]>=x){
            cnt[i]=cnt[i-1]+1;
            sum[i]=sum[i-1]+v[i];
            }else{
                cnt[i]=cnt[i-1];
                sum[i]=sum[i-1];
            }
        }
    
    for(int i=1;i<=m;i++){
        int c=cnt[r[i]]-cnt[l[i]-1];
        int v=sum[r[i]]-sum[l[i]-1];
        y+=c*v;
    }
    return y;
}

signed main(){
    
    cin>>n>>m>>s;
    int left=0,right=0;
     w.assign(n+1,0);
     v.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
        right=max(right,w[i]);
    }
    right++;
    l.assign(m+1,0);
    r.assign(m+1,0);
    cnt.assign(n+1,0);
    sum.assign(n+1,0);
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
    }
    int mid;
    while(left<right){
        mid=left+(right-left)/2;
        int y=check(mid);
        if(y>s){
            left=mid+1;
        }else if(y<s) {
            right=mid-1;
        }else if(y==s){
            ans=0;
            break;
        }
        ans=min(ans,llabs(y-s));
    }
    cout<<ans<<endl;
}