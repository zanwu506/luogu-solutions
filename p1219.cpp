#include<bits/stdc++.h>
using namespace std;

int total=0;
int n;
vector<int> ans;
vector<bool> diag1,diag2,col;

void dfs(int row){
    if(row==n){
        total++;
        if(total<=3){
            for(int i=0;i<n;i++){
                if(i>0)cout<<' ';
                cout<<ans[i]+1;
            }
            cout<<endl;
        }
        return;
    }
    for(int c=0;c<n;c++){
        int d1=row-c+n-1;
        int d2=row+c;
        if(!col[c]&&!diag1[d1]&&!diag2[d2]){
            ans[row]=c;
            col[c]=true;
            diag1[d1]=true;
            diag2[d2]=true;
            dfs(row+1);
            col[c]=false;
            diag1[d1]=false;
            diag2[d2]=false;
        }
    }
}

int main(){
    cin>>n;
    ans.resize(n);
    diag1.resize(2*n-1);
    diag2.resize(2*n-1);
    col.resize(n);
    dfs(0);
    cout<<total<<endl;
}