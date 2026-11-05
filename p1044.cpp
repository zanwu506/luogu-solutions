#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> res(n+1,0);
    res[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            res[i]+=res[j]*res[i-1-j];
        }
    }
    cout<<res[n]<<endl;
    return 0;
}