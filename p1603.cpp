#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;
    getline(cin,line);
    if(!line.empty()&&line.back()=='.'){
        line.pop_back();
    }
    vector<string> words;
    stringstream ss(line);
    string word;
    while(ss>>word){
        words.push_back(word);
    }
    map<string,int> mp;
    vector<string> nums={"zero", "one", "two", "three", "four", "five",
                         "six", "seven", "eight", "nine", "ten",
                           "eleven", "twelve", "thirteen", "fourteen", 
                           "fifteen", "sixteen", "seventeen", "eighteen",
                            "nineteen", "twenty"};
    for(int i = 0; i <= 20; i++){
        mp[nums[i]] = i;
    }
    mp["a"]=1;
    mp["both"]=2;
    mp["another"]=1;
    mp["first"]=1;
    mp["second"]=2;
    mp["third"]=3;
    vector<string> parts;
    for(const string& w:words){
        if(mp.count(w)){
            int val=mp[w];
            int mod=(val*val)%100;
            string s=to_string(mod);
            if(s.size()==1)s="0"+s;
            parts.push_back(s);
        }
        
    }
    if(parts.empty()){
        cout<<0<<endl;
        return 0;
    }
    sort(parts.begin(),parts.end());
    string ans="";
    for( const string& p:parts){
        ans+=p;
    }
    int pos=0;
    while(pos<ans.size()&&ans[pos]=='0')pos++;
    if(pos==ans.size()){
        cout<<0<<endl;
    }else{
    cout<<ans.substr(pos)<<endl;
    }
    return 0;


    
}