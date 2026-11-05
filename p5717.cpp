#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a<b){
        swap(a,b);
    }
    if(a<c){
        swap(a,c);
    }
    if(b<c){
        swap(b,c);
    }

    if(b+c<=a){
        cout<<"Not triangle"<<endl;
        return 0;
    }
    if(c*c+b*b==a*a){
        cout<<"Right triangle"<<endl;
    }
    if(c*c+b*b>a*a){
        cout<<"Acute triangle"<<endl;
    }
    if(c*c+b*b<a*a){
        cout<<"Obtuse triangle"<<endl;
    }
    if(c==b||a==b){
        cout<<"Isosceles triangle"<<endl;
    }
    if(a==b&&b==c){
        cout<<"Equilateral triangle"<<endl;
    }
    return 0;
}