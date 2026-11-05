#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int ,int>> cows(n);
    vector<int> id(n);
    for(int i=0;i<n;i++){
        cin>>cows[i].first>>cows[i].second;
        id[i]=cows[i].second;
    }
    sort(id.begin(),id.end());
    id.erase(unique(id.begin(),id.end()),id.end());
    for(int i=0;i<n;i++){
        cows[i].second=lower_bound(id.begin(),id.end(),cows[i].second)-id.begin();

    }
    sort(cows.begin(),cows.end());
    int len=id.size();
    int left=0;
    int distinct=0;
    int ans=INT_MAX;
    vector<int> cnt(len+1,0);
    for(int right=0;right<n;right++){
        int t=cows[right].second;
        if(cnt[t]==0){
            distinct++;
        }
        cnt[t]++;

        while(distinct==len){
            ans=min(ans,cows[right].first-cows[left].first);
            cnt[cows[left].second]--;
            if(cnt[cows[left].second]==0){
                distinct--;
            }
            left++;
        }
    }
    cout<<ans<<endl;
}