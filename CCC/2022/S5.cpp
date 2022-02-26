#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAX=2*1e5;

int n;
string s;
int cost[MAX];

int par[MAX];
vector<int>adj[MAX];

int dp[MAX][2][2];//is on/off, came from up/down

void calcDP(int p){
    int v1=0;
    int v2=0;
    bool check0=true;
    bool check1=true;
    for(auto&i:adj[p]){
        if(i==par[p])continue;
        par[i]=p;
        calcDP(i);
        if(s[p]=='N'){
            dp[p][0][0]+=min(min(dp[i][0][0],dp[i][0][1]),min(dp[i][1][0],dp[i][1][1]));
            if(min(dp[i][0][1],dp[i][1][1])!=INT_MAX)dp[p][1][0]+=min(dp[i][0][1],dp[i][1][1]);
            else check0=false;
            v1+=min(min(dp[i][0][0],dp[i][0][1]),min(dp[i][1][0],dp[i][1][1]));
            if(v2!=INT_MAX&&min(dp[i][0][1],dp[i][1][1])!=INT_MAX)v2+=min(dp[i][0][1],dp[i][1][1]);
            else v2=INT_MAX;
        }
        else{
            dp[p][0][0]+=min(min(dp[i][0][0],dp[i][0][1]),min(dp[i][1][0],dp[i][1][1]));
            dp[p][0][1]+=min(min(dp[i][0][0],dp[i][0][1]),min(dp[i][1][0],dp[i][1][1]));
            if(min(dp[i][0][1],dp[i][1][1])!=INT_MAX)dp[p][1][0]+=min(dp[i][0][1],dp[i][1][1]);
            else check0=false;
            if(min(dp[i][0][1],dp[i][1][1])!=INT_MAX)dp[p][1][1]+=min(dp[i][0][1],dp[i][1][1]);
            else check1=false;
        }
    }
    if(!check0)dp[p][1][0]=INT_MAX;
    if(!check1)dp[p][1][1]=INT_MAX;
    if(s[p]=='N'){
        dp[p][0][1]=INT_MAX;
        for(auto&i:adj[p]){
            if(i==par[p])continue;
            if(dp[i][0][1]==INT_MAX)continue;
            int cv1=v1;
            cv1-=min(min(dp[i][0][0],dp[i][0][1]),min(dp[i][1][0],dp[i][1][1]));
            cv1+=dp[i][0][1];
            dp[p][0][1]=min(dp[p][0][1],cv1);
        }

        dp[p][1][1]=INT_MAX;
        if(v2!=INT_MAX){
            for(auto&i:adj[p]){
                if(i==par[p])continue;
                if(dp[i][0][1]==INT_MAX)continue;
                int cv2=v2;
                cv2-=min(dp[i][0][1],dp[i][1][1]);
                cv2+=dp[i][0][1];
                dp[p][1][1]=min(dp[p][1][1],cv2);
            }
        }
    }
    dp[p][0][0]+=cost[p];
    if(dp[p][0][1]!=INT_MAX)dp[p][0][1]+=cost[p];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin>>s;
    for(int i=0;i<n;i++)cin>>cost[i];
    memset(par,-1,sizeof(par));
    calcDP(0);
    cout<<min(dp[0][0][1],dp[0][1][1])<<"\n";
}
