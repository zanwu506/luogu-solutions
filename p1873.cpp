#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long m;
    cin>>n>>m;
    vector<int> a(n);
    int left=0,right=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>right){
            right=a[i];
        }
    }
    while(left<right){
        int mid=left+(right-left+1)/2;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(a[i]-mid>0){
                sum+=a[i]-mid;
            }
        }
        if(sum>=m){
            left=mid;
        }else{
            right=mid-1;
        }
    }
    cout<<right<<endl;
    return 0;
}