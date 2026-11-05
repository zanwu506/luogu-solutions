#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=100005;
struct node{
    int sum,add,mul;
}tree[4*MAXN];
int m;
int a[MAXN];
void build(int p,int l,int r){
    if(l==r){
        tree[p].sum=a[l]%m;
        tree[p].add=0;
        tree[p].mul=1;
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tree[p].sum = (tree[p*2].sum + tree[p*2+1].sum)%m;
    tree[p].add=0;
    tree[p].mul=1;
}
void push_down(int p,int l,int r){
    if(tree[p].add!=0||tree[p].mul!=1){
        int mid=(l+r)/2;
        int left=p*2;
        int right=p*2+1;
        tree[left].sum=(tree[left].sum*tree[p].mul+tree[p].add*(mid-l+1))%m;
        tree[right].sum=(tree[right].sum*tree[p].mul+tree[p].add*(r-mid))%m;
        tree[left].add=(tree[p].mul*tree[left].add+tree[p].add)%m;
        tree[left].mul=(tree[left].mul*tree[p].mul)%m;
        tree[right].add=(tree[p].mul*tree[right].add+tree[p].add)%m;
        tree[right].mul=(tree[right].mul*tree[p].mul)%m; 
        tree[p].add=0;
        tree[p].mul=1;
    }
}
void update_add(int p,int l,int r,int ql,int qr,int k){
    if(ql<=l&&qr>=r){
        tree[p].sum=(tree[p].sum+(r-l+1)*k)%m;
        tree[p].add=(tree[p].add+k)%m;
        return;
    }
    push_down(p,l,r);
    int mid=(l+r)/2;
    if(ql<=mid)update_add(p*2,l,mid,ql,qr,k);
    if(qr>mid)update_add(p*2+1,mid+1,r,ql,qr,k);
    tree[p].sum=(tree[p*2].sum+tree[p*2+1].sum)%m;
}
void update_mul(int p,int l,int r,int ql,int qr,int k){
    if(ql<=l&&qr>=r){
        tree[p].sum=(tree[p].sum*k)%m;
        tree[p].mul=(tree[p].mul*k)%m;
        tree[p].add=(tree[p].add*k)%m;
        return ;
    }
    push_down(p,l,r);
    int mid=(l+r)/2;
    if(ql<=mid)update_mul(p*2,l,mid,ql,qr,k);
    if(qr>mid)update_mul(p*2+1,mid+1,r,ql,qr,k);
    tree[p].sum=(tree[p*2].sum+tree[p*2+1].sum)%m;
}
int query(int p,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r){
        return tree[p].sum;
    }
    push_down(p,l,r);
    int ans=0;
    int mid=(r+l)/2;
    if(ql<=mid)ans=(ans+query(p*2,l,mid,ql,qr))%m;
    if(qr>mid)ans=(ans+query(p*2+1,mid+1,r,ql,qr))%m;
    return ans;
}

signed main(){
    int n,q;
    cin>>n>>q>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while(q--){
        int type, x,y;
        cin>>type>>x>>y;
        if(type==3){
            int ans=query(1,1,n,x,y);
            cout<<ans%m<<endl;
        }else if(type==1){
            int k;
            cin>>k;
            update_mul(1,1,n,x,y,k);
        }else if(type==2){
            int k;
            cin>>k;
            update_add(1,1,n,x,y,k);
        }
    }
    return 0;
}