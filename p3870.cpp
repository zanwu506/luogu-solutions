#include<bits/stdc++.h>
using namespace std;

 int n,m;
const int MAXN=100005;
struct Node{
    int sum;
    int lazy;
}tree[MAXN*4];

void build(int p,int l,int r){
    tree[p].lazy=0;
    tree[p].sum=0;
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
}
void push_down(int p,int l,int r){
    if(tree[p].lazy!=0){
        // tree[p].sum=r-l+1-tree[p].sum;
        // tree[p].lazy^=1;
        tree[p*2].lazy^=1;
        tree[p*2+1].lazy^=1;
        int mid=(r+l)/2;
        tree[p*2].sum=mid-l+1-tree[p*2].sum;
        tree[p*2+1].sum=r-mid-tree[p*2+1].sum;
        tree[p].lazy=0;
    }
}

void update(int p,int ql,int qr,int l,int r){
    if(ql<=l&&qr>=r){
        tree[p].sum=r-l+1-tree[p].sum;
        tree[p].lazy^=1;
        return;
    }
    push_down(p,l,r);
    int mid=(l+r)/2;
    if(ql<=mid)update(p*2,ql,qr,l,mid);
    if(qr>mid)update(p*2+1,ql,qr,mid+1,r);
    tree[p].sum=tree[p*2].sum+tree[p*2+1].sum;
}

int query(int p,int ql,int qr,int l,int r){
    if(ql<=l&&qr>=r){
        return tree[p].sum;
    }   
    push_down(p,l,r);
    int ans=0;
    int mid=(l+r)/2;
    if(ql<=mid)ans+=query(p*2,ql,qr,l,mid);
    if(qr>mid)ans+=query(p*2+1,ql,qr,mid+1,r);
    return ans;
}

int main(){
   
    cin>>n>>m;
    build(1,1,n);
    while(m--){
        int c,a,b;
        cin>>c>>a>>b;
        if(c==0){
            update(1,a,b,1,n);
        }else{
            int ans=query(1,a,b,1,n);
            cout<<ans<<endl;
        }
    }
    return 0;
}