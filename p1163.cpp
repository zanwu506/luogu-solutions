#include<bits/stdc++.h>
using namespace std;

int main(){
    long long w0,w,m;
    cin>>w0>>w>>m;
    double low=0,high=3;
    while((high-low)>1e-10){
        double mid=(high+low)/2.0;
        double w1=w0;
        for(int i=0;i<m;i++){
            w1=w1*(1+mid)-w;
        }
        if(w1>0){
            high=mid;
        }else{
            low=mid;
        }
    }
    printf("%.1f",low*100);
    return 0;
}