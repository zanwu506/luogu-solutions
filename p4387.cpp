#include<bits/stdc++.h>
using namespace std;

void solve(int t){
    vector<int> a(t);
    vector<int> b(t);
    stack<int> c;
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    for(int i=0;i<t;i++){
        cin>>b[i];
    }
    int j=0,k=0;
    c.push(a[j]);
    while(j<t){
        if(!c.empty()&&c.top()==b[k]){
            c.pop();
            k++;
        }else{
            j++;
            c.push(a[j]);
        }
    }
    if(k==t){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
    

}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        solve(t);
    }
    return 0;
}