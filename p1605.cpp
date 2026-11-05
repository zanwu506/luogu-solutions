#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int sx,sy,fx,fy;
int cnt=0;
vector<vector<bool>> mp;
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};

void dfs(int x,int y){
    if(x==fx&&y==fy){
        cnt++;
        return;
    }
    for(int i=0;i<4;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&mp[tx][ty]){
            mp[tx][ty]=false;
            dfs(tx,ty);
            mp[tx][ty]=true;
        }else{
            continue;
        }
    }
    return;

}

int main(){
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    mp.assign(n+1,vector<bool>(m+1,true));
    for(int i=0;i<t;i++){
        int x,y;
        cin>>x>>y;
        mp[x][y]=false;
    }
    mp[sx][sy]=false;
    dfs(sx,sy);
    cout<<cnt<<endl;
    return 0;
}