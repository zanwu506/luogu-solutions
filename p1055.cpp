#include<bits/stdc++.h>
using namespace std;
int main(){
    string isbn;
    cin>>isbn;
    int sum=0;
    int cnt=1;
    for(int i=0;i<isbn.length()-1;i++){
        if(isbn[i]!='-'){
            sum+=(isbn[i]-'0')*cnt;
            cnt++;
        }
    }
    int mod=sum%11;
    char correct=(mod%10==0)?'X':(char)('0'+mod);
    if(isbn[isbn.length()-1]==correct){
        cout<<"Right"<<endl;
        
    }else{
        isbn[isbn.length()-1]=correct;
        cout<<isbn<<endl;
    }
return 0;
}