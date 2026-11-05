#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),[](const string& a,const string& b){
        return a+b>b+a;
    });
    string ans="";
    for(int i=0;i<n;i++){
        ans+=a[i];
    };
    cout<<ans<<endl;
    return 0;
}