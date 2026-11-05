#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a;
int cnt=0;
vector<int>ans;
bool isPrime(int x){
    if(x<=1)return false;
    if(x==2)return true;
    if(x%2==0)return false;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
void dfs(int i){
    if(ans.size()==k){
        int sum=0;
        for(int a:ans)sum+=a;
        if(isPrime(sum)){
            cnt++;
        }
        return;
    }
    if(i==n)return;
//剪枝
if(ans.size()+n-i<k)return;
    dfs(i+1);
    ans.push_back(a[i]);
    dfs(i+1);
    ans.pop_back();
    return;
}

int main(){
    cin>>n>>k;
    a.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0);
    cout<<cnt<<endl;
}