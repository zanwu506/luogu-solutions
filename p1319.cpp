#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> a(n,string(n,' '));
    char cnt='0';
    int temp;
    int row=0 ,col=0;
    while(cin>>temp&&row<n){
        for(int i=0;i<temp;i++){
            a[row][col]=cnt;
            col++;
            if(col==n){
                row++;
                col=0;
            }
        }
        cnt=(cnt=='0')?'1':'0';
    }
    for(int i=0;i<n;i++){
        cout << a[i]<<'\n';
    }
    return 0;

}