#include<bits/stdc++.h>
using namespace std;

const int n=10;
struct State
{
    int x;
    int y;
    int dir;
};
char grid[n][n];
bool is_valid(int x,int y){
    return x>=0&&x<n&&y>=0&&y<n&&grid[x][y]!='*';
}
bool visited[n][n][4][n][n][4];
int main(){
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    memset(visited,false,sizeof(visited));
    State John,Cow;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char temp;
            if(cin>>temp){
                grid[i][j]=temp;
                if(temp=='F'){
                    John.x=i;
                    John.y=j;
                    John.dir=0;
                }else if(temp=='C'){
                    Cow.x=i;
                    Cow.y=j;
                    Cow.dir=0;
                }

            }
        }
    }
    int minites=0;
    while(true){
        if(John.x==Cow.x&&John.y==Cow.y){
            cout<<minites<<endl;
            return 0;
        }
        if(visited[John.x][John.y][John.dir][Cow.x][Cow.y][Cow.dir]){
            cout<<0<<endl;
            return 0;
        }
        visited[John.x][John.y][John.dir][Cow.x][Cow.y][Cow.dir]=true;
        int jx=John.x+dx[John.dir];
        int jy=John.y+dy[John.dir];
        if(is_valid(jx,jy)){
            John.x=jx;
            John.y=jy;
        }else{
            John.dir=(John.dir+1)%4;
        }
        int cx=Cow.x+dx[Cow.dir];
        int cy=Cow.y+dy[Cow.dir];
        if(is_valid(cx,cy)){
            Cow.x=cx;
            Cow.y=cy;
        }else{
            Cow.dir=(Cow.dir+1)%4;
        }
        minites++;
    }
    return 0;
}