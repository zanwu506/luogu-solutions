#include<bits/stdc++.h>
using namespace std;


const int MAXN=200005;
struct Node{
    int lmax,rmax,ans;
    int lv,rv;
}tree[4*MAXN];

void push_up(int p,int l,int r){
    int ls=p*2;
    int rs=p*2+1;
    tree[p].lv=tree[ls].lv;
    tree[p].rv=tree[rs].rv;
    int mid=(l+r)/2;
    tree[p].lmax=tree[ls].lmax;
    tree[p].rmax=tree[rs].rmax;
    tree[p].ans=max(tree[ls].ans,tree[rs].ans);
    if(tree[ls].rv!=tree[rs].lv){
        if(tree[ls].lmax==mid-l+1){
            tree[p].lmax=tree[ls].lmax+tree[rs].lmax;
        }
        if(tree[rs].rmax==r-mid){
            tree[p].rmax=tree[rs].rmax+tree[ls].rmax;
        }
        tree[p].ans=max({tree[ls].ans,tree[rs].ans,tree[ls].rmax+tree[rs].lmax});

    }
}
void build(int p,int l,int r){
    if(l==r){
        tree[p].lv=0;
        tree[p].rv=0;
        tree[p].lmax=1;
        tree[p].rmax=1;
        tree[p].ans=1;
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    push_up(p,l,r);
}
void update(int p,int l,int r ,int x){
    if(l==r){
        tree[p].lv^=1;
        tree[p].rv=tree[p].lv;
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid)update(p*2,l,mid,x);
    if(x>mid)update(p*2+1,mid+1,r,x);
    push_up(p,l,r);
}

int query(int p,int l,int r){
    return tree[p].ans;
}


int main(){
    int n,q;
    cin>>n>>q;
    build(1,1,n);
    while(q--){
        int x;
        cin>>x;
        update(1,1,n,x);
        int ans=query(1,1,n);
        cout<<ans<<endl;
    }

    return 0;
}