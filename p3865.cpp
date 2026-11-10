#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;
int a[maxn];
int tree[maxn];
void build(int p,int l,int r){
    if(l==r){
        tree[p]=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tree[p]=max(tree[p*2],tree[p*2+1]);
}
int query(int p,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r){
        return tree[p];
    }
    int mid=(l+r)/2;
    int ans=INT_MIN;
    if(ql<=mid)ans=max(ans,query(p*2,l,mid,ql,qr));
    if(qr>mid)ans=max(ans,query(p*2+1,mid+1,r,ql,qr));
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while(m--){
        int x,y;
        cin>>x>>y;
        cout<<query(1,1,n,x,y)<<endl;
    }
    return 0;
}