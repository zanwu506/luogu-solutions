#include<bits/stdc++.h>
using namespace std;
int main(){
    string a1,a2,a3,a4;
    getline(cin,a1);
    getline(cin,a2);
    getline(cin,a3);
    getline(cin,a4);
    string a=a1;
    a+=a2;
    a+=a3;
    a+=a4;
    map<char,int> mp;
    for(int i=0;i<26;i++){
        mp['A'+i]=0;
    }
    for(const char & c:a){
        if(mp.count(c)){
            mp[c]++;
        }
    }
    int maxVal=0;
    for(int i=0;i<26;i++){
        if(mp['A'+i]>maxVal){
            maxVal=mp['A'+i];
        }
    }
    vector<vector<char>> ans(maxVal,vector<char>(26,' '));
    for(int i=0;i<maxVal;i++){
        for(int j=0;j<26;j++){
            if(i+mp['A'+j]<maxVal){
                ans[i][j]=' ';
            }else ans[i][j]='*';
        }
    }
    for(int i=0;i<maxVal;i++){
        for(int j=0;j<26;j++){
            cout<<ans[i][j];
            if(j!=25){
                cout<<' ';
            }
        }
        cout<<endl;
    }
    for(int i=0;i<26;i++){
        cout<<char('A'+i);
        if(i!=25)cout<<' ';
    }
    return 0;
}