#include<bits/stdc++.h>
using namespace std;

const int MAXN=100005;
int a[MAXN];
struct Node{
    int maxv,minv;
}tree[4*MAXN];

void build(int p,int l,int r){
    if(l==r){
        tree[p].maxv=a[l];
        tree[p].minv=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tree[p].maxv=max(tree[p*2].maxv,tree[p*2+1].maxv);
    tree[p].minv=min(tree[p*2].minv,tree[p*2+1].minv);
}
pair<int,int> query(int p,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r){
        return {tree[p].maxv,tree[p].minv};
    }
    int ma=-1,mi=1e9;
    int mid=(l+r)/2;
    if(ql<=mid){
        auto ans=query(p*2,l,mid,ql,qr);
        ma=max(ma,ans.first);
        mi=min(mi,ans.second);
    }
    if(qr>mid){
        auto ans=query(p*2+1,mid+1,r,ql,qr);
        ma=max(ma,ans.first);
        mi=min(mi,ans.second);
    }
    return {ma,mi};
}

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while(q--){
        int a,b;
        cin>>a>>b;
        auto res=query(1,1,n,a,b);
        cout<<res.first-res.second<<endl;
    }
    return 0;
}