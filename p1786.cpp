#include<bits/stdc++.h>
using namespace std;

struct Member{
    string name;
    string position;
    int  contribution;
    int level;
    int order;
};
int getPositionRank(string a){
    if(a=="BangZhu")return 0;
    if(a=="FuBangZhu")return 1;
    if(a=="HuFa")return 2;
    if(a=="ZhangLao")return 3;
    if(a=="TangZhu")return 4;
    if(a=="JingYing")return 5;
    if(a=="BangZhong")return 6;
}
int main(){
    int n;
    cin>>n;
    vector<Member> members(n);
    for(int i=0;i<n;i++){
        cin>>members[i].name>>members[i].position>>members[i].contribution>>members[i].level;
        members[i].order=i;
    }
    vector<Member> toAdjust;
    for(const auto& m :members){
        if(m.position!="BangZhu"&&m.position!="FuBangZhu"){
            toAdjust.push_back(m);
        }
    }
    sort(toAdjust.begin(),toAdjust.end(),[](const Member& a,const Member& b){
        if(a.contribution!=b.contribution)return a.contribution>b.contribution;
        return a.order<b.order;
    });
    for(int i=0;i<toAdjust.size();i++){
        if(i<2){
            toAdjust[i].position="HuFa";
        }else if(i<6){
            toAdjust[i].position="ZhangLao";
        }else if(i<13){
            toAdjust[i].position="TangZhu";
        }else if(i<38){
            toAdjust[i].position="JingYing";
        }else toAdjust[i].position="BangZhong";
    }
    vector<Member> Adjusted;
    for(const auto& m :members){
        if(m.position=="BangZhu"||m.position=="FuBangZhu"){
            Adjusted.push_back(m);
        }
    }
    for(int i=0;i<toAdjust.size();i++){
        Adjusted.push_back(toAdjust[i]);
    }
    sort(Adjusted.begin(),Adjusted.end(),[](const Member& a,const Member& b ){
        int pa=getPositionRank(a.position);
        int pb=getPositionRank(b.position);
        if(pa!=pb)return pa<pb;
        else if(a.level!=b.level)return a.level>b.level;
        else return a.order<b.order;
    });
    for(int  i=0;i<n;i++){
        cout<<Adjusted[i].name<<" "<<Adjusted[i].position<<" "<<Adjusted[i].level<<endl;        
    }
    return 0;
}