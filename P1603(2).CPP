#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    getline(cin,line);
    if(line.size()!=0&&line.back()=='.'){
        line.pop_back();
    }
    vector<string> words;
    stringstream ss(line);
    string word;
    int i=0;
    while(ss>>word){
        words.push_back(word);
    }
    map<string,int> mp;
    vector<string> nums={"zero","one","two","three","four","five","six",
                        "seven","eight","nine","ten","eleven",
                    "twelve","thirteen","fourteen","fifteen","sixteen",
                "seventeen","eighteen","nineteen","twenty"};
    i=0;
    for(i=0;i<=20;i++){
        mp[nums[i]]=i;
    }
    mp["a"]=1;
    mp["both"]=2;
    mp["another"]=1;
    mp["first"]=1;
    mp["second"]=2;
    mp["third"]=3;
    vector<string> ans;
    for(const string& w:words){
        if(mp.count(w)){
            int val=mp[w];
            int mod=val*val%100;
            string str=to_string(mod);
            if(str.size()==1){
                str="0"+str;
            }
            ans.push_back(str);
        }

    }
    if(ans.size()==0){
        cout<<0<<endl;
        return 0;
    }
    sort(ans.begin(),ans.end());
    string ans2="";
    for(const string& a:ans){
        ans2+=a;
    }
    int pos=0;
    while(pos<ans2.size()&&ans2[pos]=='0'){
        pos++;
    }
    if(pos==ans2.size()){
        cout<<0<<endl;
    }else{
        cout<<ans2.substr(pos)<<endl;
    }
    return 0;
}