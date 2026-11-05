#include<bits/stdc++.h>
using namespace  std;


int main(){
    int t,i=0;
    int a[30];
    long long sum=0;
    while(cin>>t){
        a[i]=t;
        sum+=t;
        i++;
    }
    long long ans=0;
    int n=1;
    for(int j=0;j<i-1;j++){
        n*=2;
    }
    ans=sum*n;
    cout<<ans<<endl;
    return 0;

}
