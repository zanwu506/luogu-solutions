#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int>ans;
void dfs(int x){
    if(ans.size()==k){
        cout<<"{";
        for(int i=0;i<ans.size();i++){
            if(i)cout<<",";
            cout<<ans[i];
        }
        cout<<"}"<<endl;
        return;
    }
    if(x>n){
        return ;
    }
    if(ans.size()+n-x+1<k){
        return ;
    }
    dfs(x+1);
    ans.push_back(x);
    dfs(x+1);
    ans.pop_back();
    return ;
}

int main(){
    
    cin>>n>>k;
    dfs(1);
}