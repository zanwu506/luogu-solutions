#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pref;
int R,C,A,B;

int getSum(int x1,int y1,int x2,int y2){
    return pref[x2][y2]-pref[x2][y1-1]-pref[x1-1][y2]+pref[x1-1][y1-1];
}
bool check(int mid){
    int rows=0;
    int top=1;
    for(int i=1;i<=R;i++){
        int cols=0;
        int left=1;
        for(int j=1;j<=C;j++){
        if(getSum(top,left,i,j)>=mid){
            cols++;
            left=j+1;
        }

    }

        if(cols>=B){
            rows++;
            top=i+1;
        }
    }
    return rows>=A;
}
int main(){
    
    cin>>R>>C>>A>>B;
    pref.assign(R+1,vector<int>(C+1,0));
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            int x;
            cin>>x;
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+x;
        }
    }
    int left=0;
    int right=pref[R][C]/(A*B);
    int ans=0;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(check(mid)){
            ans=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}