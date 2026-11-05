#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,p;
    cin>>n>>p;
    vector<int> a(n),b(n);
    long long sum_a=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        sum_a+=a[i];
    }
    if(sum_a<=p){
        cout<<-1<<endl;
        return 0;
    }
    auto check=[&](double t){
        double need=0;
        for(int i=0;i<n;i++){
            double consume=a[i]*t;
            if(consume>b[i]){
                need+=consume-b[i];
            }
        }
        return need<=p*t;
    };
    double low=0,high=1e10;
    for(int i=0;i<100;i++){
        double mid=(low+high)/2.0;
        if(check(mid)){
            low=mid;
        }else{
            high=mid;
        }
    }
    printf("%.10f\n", low);
    return 0;
}