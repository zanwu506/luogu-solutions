#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int solve(vector<int> &a,vector<int>& b,int left,int right){
    if(left>=right)return 0;
    int ans=0;
    int mid=left+(right-left)/2;
    ans+=solve(a,b,left,mid);
    ans+=solve(a,b,mid+1,right);
    int i=left,j=mid+1,k=left;
    while(i<=mid&&j<=right){
        if(a[i]>a[j]){
            b[k++]=a[j++];
            ans+=mid-i+1;
        }else{
            b[k++]=a[i++];
        }
    }
    while(i<=mid){b[k++]=a[i++];}
    while(j<=right){b[k++]=a[j++];}
    for(int p=left;p<=right;p++)a[p]=b[p];
    return ans;
}

signed main(){
    cin>>n;
    vector<int>a(n+1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>tmp(n+1,0);
    int ans=solve(a,tmp,0,n-1);
    cout<<ans<<endl;
}