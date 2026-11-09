#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;
int a[maxn],temp[maxn];
int n;
void solve(int l,int r){
    if(l>=r)return;
    int mid=(l+r)/2;
    solve(l,mid);
    solve(mid+1,r);
    int i=l;
    int j=mid+1;
    int k=l;
    while(i<=mid&&j<=r){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }else{
            temp[k++]=a[j++];
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=r)temp[k++]=a[j++];
    for(int i=l;i<=r;i++){
        a[i]=temp[i];
    }
}
int main(){
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    solve(1,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
    
}