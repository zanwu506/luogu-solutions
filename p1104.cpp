#include<bits/stdc++.h>
using namespace std;
struct Stu{
    string name;
    int y;
    int m;
    int d;
    int order;
};
int main(){
    int n;
    cin>>n;
    vector<Stu> stus(n);
    for(int i=0;i<n;i++){
        cin>>stus[i].name>>stus[i].y>>stus[i].m>>stus[i].d;
        stus[i].order=i;
    }
    sort(stus.begin(),stus.end(),[](const Stu& a,const Stu& b){
        if(a.y!=b.y)return a.y<b.y;
        else if(a.m!=b.m)return a.m<b.m;
        else if(a.d!=b.d)return a.d<b.d;
        return a.order>b.order;
    });
    for(int i=0;i<n;i++){
        cout<<stus[i].name<<endl;
    }
    return 0;
}