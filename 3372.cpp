#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=100005;
int n,m;
int a[MAXN];
int tree[4*MAXN];
int lazy[4*MAXN];

void build(int p,int left,int right){
    if(left==right){
        tree[p]=a[left];
        return;
    }
    int mid=(left+right)/2;
    build(p*2,left,mid);
    build(p*2+1,mid+1,right);
    tree[p]=tree[p*2]+tree[p*2+1];
}

void put_down(int p,int l,int r){
    if(lazy[p]!=0){
        int mid=(l+r)/2;
        int left=p*2;
        int right=p*2+1;
        tree[left]+=lazy[p]*(mid-l+1);
        tree[right]+=lazy[p]*(r-mid);
        lazy[left]+=lazy[p];
        lazy[right]+=lazy[p];
        lazy[p]=0;
    }
}

void update(int p,int pl,int pr,int l,int r,int k){
    if(pl<=l&&pr>=r){
        tree[p]+=k*(r-l+1);
        lazy[p]+=k;
        return;
    }
    int mid=(l+r)/2;
    put_down(p,l,r);
    if(pl<=mid){
        update(p*2,pl,pr,l,mid,k);
    }
    if(pr>mid){
        update(p*2+1,pl,pr,mid+1,r,k);
    }
    tree[p]=tree[p*2]+tree[p*2+1];
}

int query(int p,int pl,int pr,int l,int r){
    if(pl<=l&&pr>=r){
        return tree[p];
    }
    int ans=0;
    put_down(p,l,r);
    int mid=(l+r)/2;
    if(pl<=mid){
        ans+=query(p*2,pl,pr,l,mid);
    }
    if(pr>mid){
        ans+=query(p*2+1,pl,pr,mid+1,r);
    }
    return ans;

}

signed main(){
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while(m--){
        int type,x,y;
        cin>>type>>x>>y;
        if(type==1){
            int k;
            cin>>k;
            update(1,x,y,1,n,k);
        }else{
            int ans=query(1,x,y,1,n);
            cout<<ans<<endl;
        }
    }
    return 0;
}