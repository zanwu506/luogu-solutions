#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> a;

bool check(int x){
    long long cnt=0;
    for(int i=0;i<n;i++){
        int t=a[i];
        if(t>x){
            cnt+=t/x;
        }
    }
    return cnt>=k;
}

int main(){
    cin>>n>>k;
    a.resize(n);
    int left=0,right=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>right){
            right=a[i];
        }
    }
    while(left<right){
        int mid=left+(right-left+1)/2;
        if(check(mid)){
            left=mid;
        }else{
            right=mid-1;
        }
    }
    cout<<left<<endl;
}