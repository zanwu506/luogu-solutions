#include<bits/stdc++.h>
using namespace std;

struct BigInt{
    vector<int> a;
    BigInt(){a.push_back(0);};
    BigInt(int x){
        if(x==0)a.push_back(0);
        while(x>0){
            a.push_back(x%10);
            x/=10;
        }
    };
    void operator*=(int x){
        int carry=0;
        for(int i=0;i<a.size();i++){
            long long cur=a[i]*1LL*x+carry;
            a[i]=cur%10;
            carry=cur/10;
        }
        while(carry){
            a.push_back(carry%10);
            carry/=10;
        }
    };
    BigInt operator/(int x) const{
        BigInt res;
        res.a.assign(a.size(),0);
        long long rem=0;
        for(int i=a.size()-1;i>=0;i--){
            long long cur=10*rem+a[i];
            res.a[i]=cur/x;
            rem=cur%x;
        }
        while(res.a.size()>1&&res.a.back()==0){res.a.pop_back();}
        return res;
    };
    bool operator<(const BigInt& other)const{
        if(a.size()!=other.a.size()){
            return a.size()<other.a.size();
        }
        for(int i=a.size()-1;i>=0;i--){
            if(a[i]!=other.a[i]){
            return a[i]<other.a[i];
                }
        }
        return false ;
    };
    string toString() const{
        string ans="";
        for(int i=a.size()-1;i>=0;i--){
            ans+=char('0'+a[i]);
        }
        return ans;
    };
};

struct minister{
    int left;
    int right;
    int product;
};
int main(){
    int n;
    cin>>n;
    int kingleft,kingright;
    cin>>kingleft>>kingright;
    vector<minister>ministers(n);
    for(int i=0;i<n;i++){
        cin>>ministers[i].left>>ministers[i].right;
        ministers[i].product=ministers[i].left*ministers[i].right;
    }
    sort(ministers.begin(),ministers.end(),[](const minister& a,const minister& b){
        return a.left*a.right<b.left*b.right;
    });
    BigInt ans(0);
    BigInt pre(kingleft);
    for(int i=0;i<n;i++){
        
        BigInt pur=pre/ministers[i].right;
        if(ans<pur)ans=pur;
        pre*=ministers[i].left;
    }
    cout<<ans.toString()<<endl;
    return 0;
}