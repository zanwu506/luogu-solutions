#include<bits/stdc++.h>
using namespace std;
const int max_n=100005;
int l[max_n],r[max_n];
bool exist[max_n];

int main(){
    int n;
    cin>>n;
    l[1]=0,r[1]=0;
    exist[1]=true;
    for(int i=2;i<=n;i++){
        int k,p;
        cin>>k>>p;
        if(p==0){
            int L=l[k];
            l[k]=i;
            if(L!=0)r[L]=i;
            l[i]=L;
            r[i]=k;
        }else if(p==1){
            int R=r[k];
            if(R!=0)l[R]=i;
            r[k]=i;
            l[i]=k;
            r[i]=R;
        }
        exist[i]=true;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        if(exist[t]){
        exist[t]=false;
        int L=l[t];
        int R=r[t];
        if(L!=0)r[L]=R;
        if(R!=0)l[R]=L;
    }
}
    int head=1;
    for(;head<=n;head++){
        if(exist[head]&&l[head]==0){
            break;
        }
    }
    vector<int> ans;
    int cur=head;
    while(cur!=0){
        ans.push_back(cur);
        cur=r[cur];
    }
    for(int k:ans){
        cout<<k<<" ";
    }
    return 0;
}