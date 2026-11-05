#include<bits/stdc++.h>
using namespace std;
int n;
bool eq(const vector<string> &a,const vector<string> &b){
    return a==b;
}

vector<string> reverse90(const vector<string> &a){
    vector<string> res=a;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[i][j]=a[n-1-j][i];
        }
    }
    return res;
}
vector<string> reverse180(const vector<string> &a){
    return reverse90(reverse90(a));
}
vector<string> reverse270(const vector<string> &a){
    return reverse90(reverse180(a));
}

vector<string> reflect(const vector<string> &a){
    vector<string> res=a;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[i][j]=a[i][n-1-j];
        }
    }
    return res;
}



int main(){
    
    cin>>n;
    vector<string> a(n);
    vector<string> b(n);
    for(int i=0;i<n;i++){
            cin>>a[i];
        
    }
    for(int i=0;i<n;i++){
       
            cin>>b[i];
        
    }
    vector<string> r90=reverse90(a);
    vector<string> r180=reverse180(a);
    vector<string> r270=reverse270(a);
    vector<string> ref=reflect(a);
    if(eq(r90,b)){
        cout<<1<<'\n';
    }else if(eq(r180,b)){
        cout<<2<<'\n';
    }else if(eq(r270,b)){
        cout<<3<<'\n';
    }else if(eq(ref,b)){
        cout<<4<<'\n';
    }else {
        vector<string> comb1 = reverse90(ref);
        vector<string> comb2 = reverse180(ref);
        vector<string> comb3 = reverse270(ref);
        if(eq(comb1,b)||eq(comb2,b)||eq(comb3,b)){
            cout<<5<<'\n';
        }else if(eq(a,b)){
            cout<<6<<'\n';
        }else cout<<7<<'\n';
    }
    return 0;
}