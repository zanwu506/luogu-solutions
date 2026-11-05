#include<bits/stdc++.h>
using namespace std;
//order machine_for time_for machine_used step last_time
int main(){
    int m,n;
    cin>>m>>n;
    vector<int> order(n*m);
    for(int i=0;i<n*m;i++){
        cin>>order[i];
        order[i]--;
    }
    vector<vector<int>> machine_for(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>machine_for[i][j];
            machine_for[i][j]--;
        }
    }
    vector<vector<int>> time_for(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>time_for[i][j];
            time_for[i][j];
        }
    }
    const int MAX_TIME=10000;
    vector<vector<bool>> machine_used(m,vector<bool>(MAX_TIME,false));
    //vector<bool> machine_used(m,false);
    vector<int> step(n,0);
    vector<int> last_time(n,0);
    for(int job:order){
        int s=step[job];
        int machine=machine_for[job][s];
        int time=time_for[job][s];
        int start=last_time[job];
        while(true){
            bool ok=true;
            for(int i=start;i<start+time;i++){
                if(machine_used[machine][i]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                break;
            }
            start++;
        }
        last_time[job]=start+time;
         for(int i=start;i<start+time;i++ ){
            machine_used[machine][i]=true;
        }
        step[job]++;
        

    }

    int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,last_time[i]);
        }
    cout<<ans<<endl;
    return 0;
}
