#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    map<char,int> mp;
   
    for(int i=0;i<26;i++){
        mp['A'+i]=i+1;
    }
    int a1=1,b1=1;
    for(int i=0;i<a.size();i++){
        a1*=mp[a[i]];
    }
    for(int i=0;i<b.size();i++){
        b1*=mp[b[i]];
    }
    if(a1%47==b1%47){
        cout<<"GO"<<endl;
    }else{
        cout<<"STAY"<<endl;
    }
    return 0;
}