#include<bits/stdc++.h>
using namespace std;
struct Farmer{
    int price;
    int total;
    int order;
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<Farmer> farms(m);
    for(int i=0;i<m;i++){
        cin>>farms[i].price>>farms[i].total;
        farms[i].order=i;
    }
    sort(farms.begin(),farms.end(),[](const Farmer& a,const Farmer& b){
        if(a.price!=b.price)return a.price<b.price;
        return a.order<b.order;
    });
    int sum=0,ans=0;
    int p=0;
    while(sum<n){
        if(sum+farms[p].total<n){
            sum+=farms[p].total;
            ans+=farms[p].price*farms[p].total;
            p++;
        }else if(sum+farms[p].total>=n){
            int temp=n-sum;
            ans+=farms[p].price*temp;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}