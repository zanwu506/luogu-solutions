#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> deep(n);
    for(int i=0;i<n;i++){
        cin>>deep[i];
    }
    int ans=deep[0];
    for(int i=1;i<n;i++){
        if(deep[i]>deep[i-1]){
            ans+=deep[i]-deep[i-1];
        }
    }
    cout<<ans<<endl;
    return 0;
}