#include<bits/stdc++.h>
using namespace std;

double getLong(int x1,int y1,int z1,int x2,int y2,int z2){
    int a=x1-x2;
    int b=y1-y2;
    int c=z1-z2;
    return sqrt(a*a+b*b+c*c);
};
struct Num{
    int x;
    int y;
    int z;
};
int main(){
    int n;
    cin>>n;
    vector<Num> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i].x>>nums[i].y>>nums[i].z;
    }
    double sum=0;
    sort(nums.begin(),nums.end(),[](const Num& a,const Num& b){
        return a.z<b.z;
    });
    for(int i=0;i<n-1;i++){
        sum+=getLong(nums[i].x,nums[i].y,nums[i].z,nums[i+1].x,nums[i+1].y,nums[i+1].z);
    }
    printf("%.3f\n",sum);
    return 0;
}