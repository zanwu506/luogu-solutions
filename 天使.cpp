#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int> a;

bool buy(int x){
    int sum=0;
    int temp=n-x;
    for(int i=n-x;i<n;i+=2){
        sum+=a[i]+a[i+1]/2;
    }
    if(sum>m)return false;
    return true;
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
    while(buy(n)==false){
        n--;
    }
    cout<<n<<endl;
    return 0;
}