#include<bits/stdc++.h>
using namespace std;
string solve(int n){
    string res;
    if(n==0)return "0";
    if(n==1)return "2(0)";
    if(n==2)return "2";
    bool first=true;
    for(int i=31;i>=0;i--){
        
        if(n&(1<<i)){
            if(!first)res+="+";
            first=false;
            if(i==0){
                res+="2(0)";
            }else if(i==1){
                res+="2";
            }else 
            res+="2("+solve(i)+")";
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    string res=solve(n);
    cout<<res<<endl;
}