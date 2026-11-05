#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    string s;
    cin>>s>>n;
    long long len=(long long)s.size();
    while(len<n){
        len*=2;
    }
    while(n>(long long)s.size()){
        long long half=len/2;
        if(n>half){
            long long offset=n-half;
            if(offset==1){
                n=half;
            }else n=offset-1;
        }
            len=half;
        
    }
    cout<<s[n-1]<<endl;
    return 0;
}