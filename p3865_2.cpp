#include<bits/stdc++.h>
using namespace std;


const int maxn=100005;
const int LOG=17;
int lg[maxn];
int st[maxn][LOG];
int main(){
    ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>st[i][0];
    }
    lg[1]=0;
    for(int i=2;i<=n;i++){
        lg[i]=lg[i/2]+1;
    }
    //st表
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++)
        st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        int k=lg[r-l+1];
        cout<<max(st[l][k],st[r-(1<<k)+1][k])<<"\n";
    }
    return 0;
}