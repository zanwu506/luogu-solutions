#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int> a;

bool check(int x){
    int cnt=1;
    int cur=0;
    for(int i=0;i<n;i++){
        if(cur+a[i]>x){
            cnt++;
            cur=a[i];
        }else{
            cur+=a[i];
        }

    }
    return cnt<=m;

}
signed main(){
    cin>>n>>m;
    a.resize(n);
    int max_val=0;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max_val){
            max_val=a[i];
        }
        sum+=a[i];
    }
    int left=max_val,right=sum;
    while(left<right){
        int mid=left+(right-left)/2;
        if(check(mid)){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    cout<<left<<endl;
    return 0;

}