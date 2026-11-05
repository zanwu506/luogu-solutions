#include<bits/stdc++.h>
using namespace std;
#define int double
int a,b,c,d;

int fn(int x){
    int t=a*x*x*x+b*x*x+c*x+d;
    if(t>0)return 1;
    else if(t==0)return 0;
    else return -1;
}

void solve(int left,int right){
    while((right-left)>0.001){
    int mid=left+(right-left)/2;
    if(fn(mid)==0){
        printf("%.2f ",mid);
        return;
    }else if(fn(mid)==fn(left)){
        left=mid;
    }else right=mid;
}
    printf("%.2f ",left);
    return;
}
signed main(){
    
    cin>>a>>b>>c>>d;
    int left=-100;
    for(int right=-99;right<=100;right++){
        int l=fn(left);
        int r=fn(right);
        if(l==0)printf("%.2f ",left);
        if(r==0){
            printf("%.2f ",right);
            left++;
            right++;
        }
        if(l*r<0){
            solve(left,right);
        }
        left++;
    }
    return 0;
}