#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> dir(n+1,0);
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        //F代表1，B代表0
        dir[i]=c=='F';
    }
    int BestK=0,BestM=INT_MAX;
    for(int K=1;K<=n;K++){
        vector<int> diff(n+2,0);
        int flip=0,cnt=0;
        bool ok=true;
        for(int i=1;i<=n;i++){
            flip+=diff[i];
            int cur=dir[i]^(flip&1);
            if(cur==0){
                if(i+K-1>n){
                    ok=false;
                    break;
                }
                flip++;
                cnt++;
                diff[i+K]--;
            }
        }
        if(ok&&cnt<BestM){
            BestK=K,BestM=cnt;
        }
    }
    cout<<BestK<<" "<<BestM<<endl;
    return 0;
}