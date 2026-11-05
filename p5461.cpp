#include<bits/stdc++.h>
using namespace std;
int n;
int a[1025][1025];

void solve(int x,int y,int size){
    if(size==1){
        return;
    }else{
        for(int i=x;i<x+size/2;i++){
            for(int j=y;j<y+size/2;j++){
                a[i][j]=0;
            }
        }
        
        solve(x+size/2,y,size/2);
        solve(x,y+size/2,size/2);
        solve(x+size/2,y+size/2,size/2);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<1025;i++){
        for(int j=0;j<1025;j++){
            a[i][j]=1;
        }
    }
    int size=1;
    for(int i=0;i<n;i++){
        size*=2;
    }
    solve(0,0,size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}