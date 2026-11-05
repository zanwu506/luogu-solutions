#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int> a;

bool buy(int x){
    int sum=0;
    if(x%2==0){
    for(int i=n-x;i<n;i+=2){
        sum+=a[i]+a[i+1]/2;
    }
}
if(x%2!=0){
    for(int i=n-x;i<n-1;i+=2){
        sum+=a[i]+a[i+1]/2;
    }
    sum+=a[n-1];
}
    return sum>m;
}

signed main(){
    cin>>n>>m;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),[](const int &a,const int &b){
        return a>b;
    });
    int  left=0,right=n;
    while(left<right){
        int mid=left+(right-left+1)/2;
        if(!buy(mid)){
            left=mid;
        }else{
            right=mid-1;
        }
    }
    cout<<left<<endl;

    
    return 0;
}