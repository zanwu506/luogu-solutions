#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=INT_MIN;
    vector<vector<int>> r(n+1,vector<int>(n+1,0));
    vector<vector<int>> sum(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>r[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+r[i][j];
        }
    }
    for(int top=1;top<=n;top++){
        for(int bottom=top;bottom<=n;bottom++){
            vector<int> col(n+1,0);
            int  cur=0;
            int maxSum=INT_MIN;
            for(int j=1;j<=n;j++){
                col[j]=sum[bottom][j]-sum[bottom][j-1]
                -sum[top-1][j]+sum[top-1][j-1];
                cur=max(col[j],cur+col[j]);
                maxSum=max(maxSum,cur);
            }
            ans=max(ans,maxSum);
        }
    }

    cout<<ans<<endl;
    return 0;
}