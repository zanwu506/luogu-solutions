#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
    vector<int> d;
    vector<int> s;
    vector<int> t;
    vector<int> nums;
bool check(int mid){
    vector<int> diff(n+2,0);
    for(int i=1;i<=mid;i++){
        diff[s[i]]+=d[i];
        diff[t[i]+1]-=d[i];
    }
    vector<int> nums3(n+1,0);
    for(int i=1;i<=n;i++){
        nums3[i]=nums3[i-1]+diff[i];
        if(nums3[i]>nums[i]){
            return false;
        }
    }
    return true;

}
    
signed main(){
    
    cin>>n>>m;
    d.assign(m+1,0);
    s.assign(m+1,0);
    t.assign(m+1,0);
    nums.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    
    for(int i=1;i<=m;i++){
        cin>>d[i]>>s[i]>>t[i];
    }
    

    int left=1,right=m;
    int mid,ans=0;
    while(left<=right){
        mid=left+(right-left)/2;
        if(check(mid)){
            left=mid+1;
            ans=mid;
        }else{
            right=mid-1;
        }
    }

    if(ans==m){
        cout<<0<<endl;
    }else{
        cout<<-1<<endl;
        cout<<ans+1<<endl;
    }
    
    return 0;
}