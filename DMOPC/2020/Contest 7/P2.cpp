#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pp;
int n;
map<pp,pp>adj;
pp bad={INT_MAX,INT_MAX};
bool take(pp a,pp b){
    if(adj.find(a)==adj.end()){
        adj[a]=bad;
        return false;
    }
    if(adj[a]!=b)return false;
    adj[a]=bad;
    return true;
}
int dx1[2][4]={{0,0,1,1},{0,1,0,1}};
int dy1[2][4]={{1,0,1,0},{0,0,1,1}};
int dx2[2][8]={{-1,-1,0,0,1,1,2,2},{-1,0,-1,1,2,0,2,1}};
int dy2[2][8]={{1,0,2,-1,-1,2,0,1},{0,-1,1,-1,0,2,1,2}};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if((a+b)%4==0){
            for(int j=0;j<4;j++)take({a+dx1[0][j],b+dy1[0][j]},{a+dx1[1][j],b+dy1[1][j]});
            for(int j=0;j<4;j++){
                pp c={a+dx1[1][j],b+dy1[1][j]};
                pp d={a+dx1[0][j],b+dy1[0][j]};
                if(adj[c]==bad)adj[c]=d;
            }
        }
        else{
            for(int j=0;j<8;j++)take({a+dx2[0][j],b+dy2[0][j]},{a+dx2[1][j],b+dy2[1][j]});
            for(int j=0;j<8;j++){
                pp c={a+dx2[1][j],b+dy2[1][j]};
                pp d={a+dx2[0][j],b+dy2[0][j]};
                if(adj[c]==bad)adj[c]=d;
            }
        }
    }
    vector<pp>outp;
    pp cur=(*adj.begin()).first;
    while(true){
        outp.push_back(cur);
        cur=adj[cur];
        if(cur==(*adj.begin()).first)break;
    }
    cout<<outp.size()<<"\n";
    for(pp i:outp)cout<<i.first<<" "<<i.second<<"\n";
}
