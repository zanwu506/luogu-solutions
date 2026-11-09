#include<bits/stdc++.h>
using namespace std;
int k,x,y;
int a[1025][1025];

void solve(int r,int c,int len,int x,int y){
    int half=len/2;
    // if(half==1){
    //     if(r==x&&c==y){
    //         cout<<r+1<<" "<<c+1<<" "<<1<<endl;
    //     }else if(r==x&&c==y-1){
    //         cout<<r+1<<" "<<c<<" "<<2<<endl;
    //     }else if(r==x+1&&c==y){
    //         cout<<r<<" "<<c+1<<" "<<3<<endl;
    //     }else{
    //         cout<<r<<" "<<c<<" "<<4<<endl;
    //     }
    // }
    if(len==1)return;
    //特殊格子在左上
    if(r+half>x&&c+half>y){
        solve(r,c,half,x,y);
        solve(r+half,c,half,r+half,c+half-1);
        solve(r,c+half,half,r+half-1,c+half);
        solve(r+half,c+half,half,r+half,c+half);
        cout<<r+half<<" "<<c+half<<" "<<1<<endl;
    }else if(r+half>x&&c+half<=y){
        //特殊格子在右上
        solve(r,c,half,r+half-1,c+half-1);
        solve(r+half,c,half,r+half,c+half-1);
        solve(r,c+half,half,x,y);
        solve(r+half,c+half,half,r+half,c+half);
        cout<<r+half<<" "<<c+half-1<<" "<<2<<endl;
    }else if(r+half<=x&&c+half>y){
        //特殊格子在左下
        solve(r,c,half,r+half-1,c+half-1);
        solve(r+half,c,half,x,y);
        solve(r,c+half,half,r+half-1,c+half);
        solve(r+half,c+half,half,r+half,c+half);
        cout<<r+half-1<<" "<<c+half<<" "<<3<<endl;
    }else if(r+half<=x&&c+half<=y){
        //特殊各自在右下
        solve(r,c,half,r+half-1,c+half-1);
        solve(r+half,c,half,r+half,c+half-1);
        solve(r,c+half,half,r+half-1,c+half);
        solve(r+half,c+half,half,x,y);
        cout<<r+half-1<<" "<<c+half-1<<" "<<4<<endl;
    }
}
int main(){
    cin>>k>>x>>y;
    int len=1;
    for(int i=1;i<=k;i++){
        len*=2;
    }
    solve(1,1,len,x,y);
    return 0;
}